#include "commander-generated/commander.h"


namespace generated {

    RODOS::Topic<corfu::Anomaly> &Commander::corfuAnomalyTopic = corfu::anomalyTopic;
    RODOS::Topic<corfu::Alive> &Commander::corfuAppIsAliveTopic = corfu::appIsAliveTopic;
    RODOS::Topic<corfu::Telecommand> &Commander::corfuTelecommandTopic = corfu::telecommandTopic;
    RODOS::Topic<corfu::Telecommand> &Commander::corfuUplinkTelecommandTopic = corfu::uplinkTelecommandTopic;

void Commander::handleTelecommand(const corfu::Telecommand& telecommand) {
    if(telecommand.serviceID != appId) return;

  switch(telecommand.subserviceID) {
      case 1:{
            handleTelecommandNOP();
        break;
      }
      case 2:{
            handleTelecommandReboot();
        break;
      }
  }
}


}
