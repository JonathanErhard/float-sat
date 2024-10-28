#pragma once

#include "anomaly.h"
#include "config.h"

#include "standard-telemetry.h"

#include "telecommand/set-collect-interval.h"



#include <corfu/protected-variable.h>
#include <corfu/test/app.h>

#include <fifo.h>
#include <subscriber.h>

namespace generated {

class Housekeeper : public corfu::test::App {
public:

  corfu::test::Topic<corfu::Alive> corfuAppIsAliveTopic;
  corfu::test::Topic<corfu::Telemetry> corfuStandardTelemetryTopic;
  corfu::test::Topic<corfu::Telemetry> corfuExtendedTelemetryTopic;


  virtual void initCollector() {}
  virtual void runCollector() = 0;


  corfu::ProtectedVariable<HousekeeperStandardTelemetry> standardTelemetry;

  corfu::ProtectedVariable<HousekeeperStandardTelemetry> &getStandardTelemetry() { return standardTelemetry; }

  uint32_t serializeStandardTelemetry(corfu::Slice<uint8_t>& slice) const {
    corfu::Accessor accessor = standardTelemetry.access();
    return accessor->serialize(slice);
  }

  virtual bool handleTelecommandNOP() = 0;
  virtual bool handleTelecommandSetCollectInterval(const SetCollectInterval& setCollectInterval) = 0;

};

}
