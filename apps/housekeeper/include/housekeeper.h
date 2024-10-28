#pragma once

#include <housekeeper-generated/housekeeper.h>
#include <common-generated/anomaly.h>

#include <corfu/map.h>
#include <ringbuffer.h>



class Housekeeper : public generated::Housekeeper {

    corfu::ProtectedVariable<std::uint16_t> collectInterval;
    std::uint16_t intervallCounter = 0;

    int64_t last_heartbeat  = 0;

    corfu::Telemetry tm;

    bool handleTelecommandNOP() override;
    bool handleTelecommandSetCollectInterval(const generated::SetCollectInterval &setCollectInterval) override;


public:
    void runCollector() override;

};
