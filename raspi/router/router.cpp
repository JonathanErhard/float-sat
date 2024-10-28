#include "rodos.h"
#include "hal/hal_uart.h"
#include <iostream>
#include <stdio.h>

#include "util.h"
void sendToLED(std::string* msg);
void sendToPython(std::string* msg);
void sendToSTM(std::string* msg);
RODOS::UDPOut udpOutPy(5555);
RODOS::UDPIn udpIn(5556);
RODOS::UDPOut udpOutLED(5554);
RODOS::UDPIn udpInLED(5553);


class PythonComms: public StaticThread<>{
    public:
PythonComms(const char* name) :
			StaticThread<>(name) {
	}
    
    RODOS::Fifo<std::string, 10> msgsToPy;
    RODOS::Fifo<std::string, 10> msgsToLED;


    void init(){
    }
    
    void run(){
                    //Msg length Rodos <-> Python = 64
        char buf[65];
        
        std::string nextToSend;
        while(true){
            if(msgsToPy.get(nextToSend)){     
                 udpOutPy.send(nextToSend.c_str(), 64);
            }
            if(msgsToLED.get(nextToSend)){     
                 udpOutLED.send(nextToSend.c_str(), 64);
            }

            if(udpIn.readyToGet()){
                int32_t l = udpIn.get(buf, 64);
                buf[l] = 0;
                if(buf[0] != 'L'){
                    std::string* toSend = new std::string(buf);
                    PRINTF("To STM from Py: %s\n", (*toSend).c_str());
                    sendToSTM(toSend);
                }
                else{
                    PRINTF("To LED from Py: %s\n", buf);
                    udpOutLED.send(buf, l);
                }
            }
            
            if(udpInLED.readyToGet()){
                int32_t l = udpInLED.get(buf, 64);
                buf[l] = 0;
                std::string* toSend = new std::string(buf);
                PRINTF("To STM from LED: %s\n", (*toSend).c_str());
                sendToSTM(toSend);
            }
                    
            suspendCallerUntil(50*MILLISECONDS+NOW());
        }
    }
    
    void sendToPython(std::string* msg){
        if(msg->length() > 64)
            PRINTF("MSG TO PYTHON TO LONG\n");
        else{
            msg->insert(msg->end(), 64-msg->size(), 'N');
            msgsToPy.put(*msg);
        }
        delete msg;
    }
    
    void sendToLED(std::string* msg){
        if(msg->length() > 64)
            PRINTF("MSG TO LED TO LONG\n");
        else{
            msg->insert(msg->end(), 64-msg->size(), 'N');
            msgsToLED.put(*msg);
        }
        delete msg;    
    }
};
PythonComms pt("pythoncomms");

HAL_UART uart2(UART_IDX4);

class SendToSTM: public StaticThread<>{
    public:
    SendToSTM(const char* name) :
			StaticThread<>(name) {
	}
    RODOS::Fifo<std::string, 10> msgsToSTM;
    
    void sendToSTM(std::string* msg){
        msgsToSTM.put(*msg);
        delete msg;
    }
    void init(){}
    std::string nextToSend;
    void run(){
        while(1){
            //Stuff to STM if there is any
            if(msgsToSTM.get(nextToSend)){
                uart2.write(nextToSend.c_str(), nextToSend.size());
            }
            //uart2.write("MAMAAA\n", 7);
            suspendCallerUntil(NOW()+100*MILLISECONDS);

        }
    }
} seTS("AS");

class BluetoothTest: public StaticThread<> {
	long long periode;
public:
	BluetoothTest(const char* name, long long periode) :
			StaticThread<>(name) {
		this->periode = periode;
	}
    
    

    char currentMsg[65];

	void init(){
		uart2.init(115200);
		uart2.config(UART_PARAMETER_HW_FLOW_CONTROL,1);
        uart2.config(UART_PARAMETER_ENABLE_DMA,64);
        currentMsg[64] = '\0';
	}
    int64_t lastMsgTime = 0;
    void evaluateMsg(){
            PRINTF("Msg: %s\n", currentMsg);

            if(currentMsg[0] == 'P'){ //Message is for Python, redirect
                std::string* toSend = new std::string(currentMsg);
                sendToPython(toSend);
            }
            else if(currentMsg[0] == 'L'){
                std::string* toSend = new std::string(currentMsg);
                sendToLED(toSend);
                
            }
            else{ //Messasge is for Rodos, do smth
                
               
            }
        }
    
	void run() {
		long long nextTime = NOW();
		char ch[65]; //Max Msg length STM->RPI
        
        
        int currentMsgIndex = 0;
		while (1) {
            //uart2.write("TEST",4);
			
            //Read UART
			int rxCnt = uart2.read(ch,1);
			if (rxCnt > 0){	//Message here?
                //PRINTF("Recv %s %d\n", ch, rxCnt);
                for(int i = 0; i <= rxCnt; i++){
                    if(ch[i]==128)continue;
                    if(ch[i]=='\0') continue;
                    
                    currentMsg[currentMsgIndex] = ch[i];
                    currentMsgIndex++;
                    
                    
                    if(currentMsgIndex > 64){
                        PRINTF("MSG ERROR2\n");
                        currentMsgIndex = 0;
                        continue;
                    }
                    
                    if(ch[i] == '#') {
                        PRINTF("EVAL\n");
                        currentMsg[currentMsgIndex] = '\0';
                        currentMsgIndex = 0;
                        evaluateMsg();
                    }

                }
                
            }
            

			nextTime += periode;
			uart2.suspendUntilDataReady();
		}
        
        
	}
};

BluetoothTest bt1("BluetoothTest", 45* MILLISECONDS);

class SendAlive: public StaticThread<>{
    public:
    SendAlive(const char* name) :
			StaticThread<>(name) {
	}

    void init(){}
    void run(){
        while(1){
            sendToSTM( new std::string("FIMGOOD#"));
            suspendCallerUntil(NOW()+5000*MILLISECONDS);

        }
    }
} SendAlive("SendAlive");

void sendToPython(std::string* msg){
    pt.sendToPython(msg);
}

void sendToSTM(std::string* msg){
    seTS.sendToSTM(msg);
}

void sendToLED(std::string* msg){
    pt.sendToLED(msg);
}
        
        
