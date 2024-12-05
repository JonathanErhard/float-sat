#include "transceiver.h"
#include "rodos.h"

/* ~~~~~ Set UART as gateway ~~~~~ *//*

static HAL_UART bluetooth(UART_IDX2); // Tx: PD5, Rx: PD6
static LinkinterfaceUART link_name_not_imp(&bluetooth, 115200, 3, 10);
static Gateway gw_name_not_imp(&link_name_not_imp, true);*/



bool Transceiver::handleTelecommandNOP() {
    RODOS::PRINTF("RADIO      -> RADIO_NOP\n");
    return true;
}

// add ID of topic to forward through the udp gateway
void Transceiver::initialize() {

    //bluetooth.init(115200);//initialize the Bluetooth for a baud rate of 115200
    uart_egse.init(115200);
    topics.init();
    topics.add(generated::radioDownTopic.topicId); // workaround, because of problem in topic generator
    gw.setTopicsToForward(&topics);

    RODOS::PRINTF("TRX ====> set up LinkInterfaceUART!!! \n");
}

void Transceiver::handleTopicRadioUpTopic(corfu::Telecommand &msg) {
    corfu::uplinkTelecommandTopic.publish(msg);
}


void Transceiver::runTxThread() {
    while(! this->corfuStandardTelemetryTopicFifo.isEmpty()) {
        corfu::Telemetry tm;
        bool stuffToSend = this->corfuStandardTelemetryTopicFifo.syncGet(tm,0);

        if(stuffToSend) {
            generated::radioDownTopic.publish(tm, true);
        }
    }

    while(! this->corfuExtendedTelemetryTopicFifo.isEmpty()) {
        corfu::Telemetry tm;
        bool stuffToSend = this->corfuExtendedTelemetryTopicFifo.syncGet(tm,0);

        if(stuffToSend) {
            generated::radioDownTopic.publish(tm, true);
        }
    }
}
