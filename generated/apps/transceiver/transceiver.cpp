#include "transceiver-generated/transceiver.h"


namespace generated {

    RODOS::Topic<corfu::Anomaly> &Transceiver::corfuAnomalyTopic = corfu::anomalyTopic;
    RODOS::Topic<corfu::Alive> &Transceiver::corfuAppIsAliveTopic = corfu::appIsAliveTopic;
    RODOS::Topic<corfu::Telecommand> &Transceiver::corfuUplinkTelecommandTopic = corfu::uplinkTelecommandTopic;
    RODOS::Topic<corfu::Telemetry> &Transceiver::corfuStandardTelemetryTopic = corfu::standardTelemetryTopic;
    RODOS::Topic<corfu::Telemetry> &Transceiver::corfuExtendedTelemetryTopic = corfu::extendedTelemetryTopic;
    RODOS::Topic<corfu::Telecommand> &Transceiver::radioUpTopic = generated::radioUpTopic;
    RODOS::Topic<corfu::Telemetry> &Transceiver::radioDownTopic = generated::radioDownTopic;

void Transceiver::handleTelecommand(const corfu::Telecommand& telecommand) {
    if(telecommand.serviceID != appId) return;

  switch(telecommand.subserviceID) {
      case 1:{
            handleTelecommandNOP();
        break;
      }
  }
}


}
