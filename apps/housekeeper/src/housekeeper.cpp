#include "housekeeper.h"

#include <corfu/node.h>
#include <corfu/tele/telemetry.h>



/**
 * @LINKEDREQ HKE_00, HKE_01
 */
void Housekeeper::runCollector() {
    corfu::Accessor ci = this->collectInterval.access();
    // auto acc = this->standardTelemetry.access();

    if(*ci == 0) { // cannot move this to initialize() because of protected variable access
        *ci = config::housekeeper::DEFAULT_COLLECT_INTERVAL;
        RODOS::PRINTF("In housekeeper collector setting ci \n");
        corfu::Accessor stdtm = this->standardTelemetry.access();
        stdtm->collectInterval = *ci; // ci.operator*();
    }

    intervallCounter++;

    // @LINKEDREQ HKE_03
    if(intervallCounter >= *ci) {
        auto stm = this->standardTelemetry.access();
        stm->iteration += intervallCounter;
        corfu::Telemetry telemetry;
        telemetry.subserviceID  = config::housekeeper::STANDARD_TELEMETRY_SUBSERVICE_ID;
        telemetry.payloadLength = static_cast<uint16_t>(getNode().serializeStandardTelemetry(telemetry.getSerializedPayloadSlice()));
        finalizeTelemetry(telemetry);
        corfu::standardTelemetryTopic.publish(telemetry);
        intervallCounter = 0;
        // RODOS::PRINTF("HKE sent tm \n");
    }
    // RODOS::PRINTF(" HKE end of collector \n");

    // send iAmAlive to local watchdog
    this->sendAlive(RODOS::NOW() + 5_s); // @LINKEDREQ ALLG_10


}

bool Housekeeper::handleTelecommandNOP() {
    RODOS::PRINTF("HKR: HKR_NOP\n");
    return true;
}

/**
 * @LINKEDREQ HKE_03
 * @param setCollectInterval
 * @return
 */
bool Housekeeper::handleTelecommandSetCollectInterval(const generated::SetCollectInterval &setCollectInterval) {
    RODOS::PRINTF("HKR: HKR_Sci\n");

    corfu::Accessor ci = this->collectInterval.access();
    *ci = setCollectInterval.intervalInSeconds;
    corfu::Accessor stdtm = this->standardTelemetry.access();

    stdtm->collectInterval = *ci;
    return true;
}
