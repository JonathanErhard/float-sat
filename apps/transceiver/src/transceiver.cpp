#include "transceiver.h"

bool Transceiver::handleTelecommandNOP() {
    RODOS::PRINTF("RADIO      -> RADIO_NOP\n");
    return true;
}

// add ID of topic to forward through the udp gateway
void Transceiver::initialize() {
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
