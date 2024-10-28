#include "commander.h"
#include "commander-generated/anomaly.h"

#include <corfu/node.h>

#define BATTERY_THRESHHOLD 7.0f

void Commander::runCommandThread() {
    // check incoming tc fifo, look at as many items as are currently set
    // (fifo will be refilled constantly), optional: just look at first X items?

    // RODOS::PRINTF("CMDThread with new geckoport2 @%u \n", this->iterations);
    this->iterations++;

    size_t elements = corfuUplinkTelecommandTopicFifo.getElementCount();
    for (uint16_t i=0u; i<elements; i++) {
        if(corfuUplinkTelecommandTopicFifo.isEmpty()) break;

        corfu::Telecommand tc;
        corfuUplinkTelecommandTopicFifo.get(tc); // @LINKEDREQ CMD_05
        this->lastCmdReceivedTime = this->iterations;

        if(tc.timeToExecute == 0u) { // immediate command @LINKEDREQ CMD_09

            this->lastCmdIndex++;  // = tc.commandIndex;

            // @LINKEDREQ CMD_03, CMD_10
            if (getNode().nodeId == tc.nodeID) {
                //TODO manual/auto check, let watchdog and commaander thru
                // publish on local node only
                corfu::telecommandTopic.publish(tc, false); // prueft das rodos nicht automatisch? nachgucken!
            } else {
                // send to network
                corfu::telecommandTopic.publish(tc, true);
            }
        }
        else {
            // if TT TC is needed fill this here
        }

    } // end of for loop

   //Commander::initiateNextState();

    // send keepalive
    this->sendAlive(RODOS::NOW()+5_s); // @LINKEDREQ ALLG_10
    // update standardTelemetry
    updateStdTM();
}


bool Commander::handleTelecommandNOP() {
    RODOS::PRINTF("COMMANDER -> NOP\n");
    return true;
}

bool Commander::handleTelecommandReboot() {
    RODOS::PRINTF("COMMANDER -> Reboot\n");
    RODOS::hwResetAndReboot();
    return true;
}

void Commander::updateStdTM() {
    corfu::Accessor acc = standardTelemetry.access();
    acc->cmdCounter = this->lastCmdIndex;
    acc->lastCmdReceivedAt = this->lastCmdReceivedTime;
}

