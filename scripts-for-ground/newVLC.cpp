#include "rodos.h"
#include "hal/hal_adc.h"
#include "hal/hal_gpio.h"

HAL_ADC adconverter(RODOS::ADC_IDX::ADC_IDX1);
HAL_GPIO blue(GPIO_063);

#define channel RODOS::ADC_CHANNEL::ADC_CH_000
#define BIT_TIME 200.0f // in milliseconds
#define ADC_LENGTH 10

//new vars
uint8_t readoutcount = 0;
uint8_t highcount = 0;
int64_t lastCharAt;
float adcValues[ADC_LENGTH];
bool analize = false;
bool frame_found = false;

enum GS_STATE {
    SYNC_HIGH,
    SYNC_LOW,
    DATA,
    END_LOW
};
GS_STATE current_state = SYNC_HIGH;
char current_char;
uint8_t char_pos;
bool had_false_2 = false;
//

constexpr int64_t CALIBRATION_PERIOD = 5 * RODOS::SECONDS;
float averageLowPulse = 3000; //it's been adjusted in the initialization process
float minLowPulse = 3000;
float maxLowPulse = 3000;
float averageHighPulse = 3000;  //it's been adjusted in the initialization process
float minHighPulse = 3000;
float maxHighPulse = 3000;

class SamplingThread : public StaticThread<> {
    bool calibrationInProgress = true;
    float backgroundLightSum = 0;
    int backgroundLightSamples = 0;
    float minValue = 10000; // For tracking minimum during high pulse calibration
    float maxValue = -1; // For tracking maximum during high pulse calibration


    public:
        SamplingThread() : StaticThread("ADC Sampling Thread", 1){ }

        void init(){ 
            adconverter.init(channel);
            
            //new here
            blue.init(1,1,0);
            lastCharAt = NOW();
            //


            PRINTF("BACKGROUND LIGHT CALIBRATION\n");
            int64_t CALIBRATION_END = RODOS::NOW() + CALIBRATION_PERIOD;
            while(calibrationInProgress) {
                float sample = adconverter.read(channel) * 3000.0f / 4095.0f;
                backgroundLightSum += sample;
                backgroundLightSamples++;
                minValue = min(minValue, sample);
                maxValue = max(maxValue, sample);
                
                //
                RODOS::PRINTF("value was: %f\n", sample);
                int64_t nextTime = RODOS::NOW() + 100* MILLISECONDS;
                while(RODOS::NOW() < nextTime){}
                //

                if (NOW() > CALIBRATION_END) {
                    PRINTF("BACKGROUND LIGHT CALIBRATION END\n");
                    averageLowPulse = backgroundLightSum / (float)backgroundLightSamples;
                    minLowPulse = minValue;
                    maxLowPulse = maxValue;
                    calibrationInProgress = false;
                    PRINTF("BG light average: %f    min: %f     max: %f\n", averageLowPulse, minValue, maxValue);
                }
            }

            //calibrate high pulse
            PRINTF("HIGH PULSE CALIBRATION starts in 10 seconds\n");
            blue.setPins(1);
            calibrationInProgress = true;
            backgroundLightSamples = 0;
            backgroundLightSum = 0;
            minValue = 10000;
            maxValue = -1;

            int64_t start = RODOS::NOW();
            while(RODOS::NOW() - start < 10 * RODOS::SECONDS);
            PRINTF("HIGH PULSE CALIBRATION starts now\n");
            CALIBRATION_END = RODOS::NOW() + CALIBRATION_PERIOD;
            while(calibrationInProgress) {
                float sample = adconverter.read(channel) * 3000.0f / 4095.0f;
                backgroundLightSum += sample;
                backgroundLightSamples++;
                minValue = min(minValue, sample);
                maxValue = max(maxValue, sample);

                //
                RODOS::PRINTF("value was: %f\n", sample);
                int64_t nextTime = RODOS::NOW() + 100* MILLISECONDS;
                while(RODOS::NOW() < nextTime){}
                //
                
                if (NOW() > CALIBRATION_END) {
                    PRINTF("HIGH LIGHT CALIBRATION END\n");
                    averageHighPulse = backgroundLightSum / (float)backgroundLightSamples;
                    minHighPulse = minValue;
                    maxHighPulse = maxValue;
                    calibrationInProgress = false;
                    PRINTF("High Pulse average: %f    min: %f     max: %f\n", averageHighPulse, minValue, maxValue);
                }
            }

            //compute threshold for filtered signal

            blue.setPins(0);
        }

        void run(){
            suspendCallerUntil(RODOS::NOW() + 5 * RODOS::SECONDS);
            float lastSample = 0;
            int nextsample = 0;
            TIME_LOOP(0, 1*MILLISECONDS) {
                //int64_t s = NOW();
                adcValues[nextsample++] = adconverter.read(channel) * 3000.0f / 4095.0f;
                
                if(NOW() - lastCharAt > 10*SECONDS){
                    lastCharAt = NOW();
                    char_pos = 0;
                    had_false_2 = false;
                    PRINTF("CHAR RESET\n");
                }
                
                //suspendCallerUntil(RODOS::NOW() + 1 * RODOS::MILLISECONDS);

                if(nextsample >= ADC_LENGTH){
                    bool current_readout = convertADCBufferToReadout();
                    nextsample = 0;


                    if(current_readout && !analize) analize = true;
                    if(analize){
                        if(current_readout) highcount++;
                        readoutcount++;
                        if(readoutcount >= BIT_TIME/(4*ADC_LENGTH)){

                            bool is_high = (highcount >= (BIT_TIME/(4*ADC_LENGTH) * 0.5f));
                            readoutcount = 0;
                            highcount = 0;

                            switch (current_state)
                            {
                                case SYNC_HIGH:
                                    if(is_high) current_state = SYNC_LOW;
                                    else {
                                        PRINTF("FALSE 1\n");

                                        analize = false;
                                        char_pos = 0;
                                        had_false_2 = false;
                                    }
                                    break;
                                
                                case SYNC_LOW:
                                    if(!is_high) current_state = DATA;
                                    else{
                                        PRINTF("FALSE 2\n");
                                        analize = false;
                                        had_false_2 = true;
                                        current_state = SYNC_HIGH;
                                    }
                                    break;

                                case DATA:
                                    //if(is_high) PRINTF("HIGH\n");
                                    //else PRINTF("LOW\n");
                                    updateChar(is_high);

                                    current_state = END_LOW;
                                    break;
                                
                                case END_LOW:
                                    current_state = SYNC_HIGH;
                                    analize = false;
                                    break;

                                default:
                                    PRINTF("default\n");
                                    break;
                            }
                        }
                    }
                    else{
                        //if(current_readout) PRINTF("HIGH\n");
                        //else PRINTF("LOW\n");
                    }
                }
                //PRINTF("took %f\n", (NOW()-s)/float(MILLISECONDS));
            }
        }

        bool convertADCBufferToReadout() {
            float sum = 0.0f;
            for(int i = 0; i < ADC_LENGTH; ++i) sum += adcValues[i];
            return ((sum/ADC_LENGTH) > (1.3f * averageHighPulse + averageLowPulse)/2);
        }

        void updateChar(bool current){
            if(had_false_2){
                had_false_2 = false;
                //PRINTF("SKIPPED CHAR UPDATE\n");
                return;
            }

            if(current) current_char |= 1UL << char_pos;
            else current_char &= ~(1UL << char_pos);

            lastCharAt = NOW();
            //PRINTF("CHAR UPDATE %d\n", char_pos);
            char_pos++;

            if(char_pos >= 8){
                PRINTF("decoded: %c\n", current_char);
                char_pos = 0;
            }
        }
} helloworldthread;