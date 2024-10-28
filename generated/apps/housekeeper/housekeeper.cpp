#include "housekeeper-generated/housekeeper.h"


namespace generated {

    RODOS::Topic<corfu::Alive> &Housekeeper::corfuAppIsAliveTopic = corfu::appIsAliveTopic;
    RODOS::Topic<corfu::Telemetry> &Housekeeper::corfuStandardTelemetryTopic = corfu::standardTelemetryTopic;
    RODOS::Topic<corfu::Telemetry> &Housekeeper::corfuExtendedTelemetryTopic = corfu::extendedTelemetryTopic;

void Housekeeper::handleTelecommand(const corfu::Telecommand& telecommand) {
    if(telecommand.serviceID != appId) return;

  switch(telecommand.subserviceID) {
      case 1:{
            handleTelecommandNOP();
        break;
      }
      case 2:{
            SetCollectInterval setCollectInterval;
            setCollectInterval.deserialize(telecommand.getSerializedParametersSlice());
            handleTelecommandSetCollectInterval(setCollectInterval);
        break;
      }
  }
}


}
