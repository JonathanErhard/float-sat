#pragma once

#include "anomaly.h"
#include "config.h"

#include "standard-telemetry.h"




#include <corfu/protected-variable.h>
#include <corfu/test/app.h>

#include <fifo.h>
#include <subscriber.h>

namespace generated {

class Commander : public corfu::test::App {
public:

  corfu::test::Topic<corfu::Anomaly> corfuAnomalyTopic;
  corfu::test::Topic<corfu::Alive> corfuAppIsAliveTopic;
  corfu::test::Topic<corfu::Telecommand> corfuTelecommandTopic;
  corfu::test::Topic<corfu::Telecommand> corfuUplinkTelecommandTopic;


  virtual void initCommandThread() {}
  virtual void runCommandThread() = 0;

  RODOS::SyncFifo<corfu::Telecommand, 12> corfuUplinkTelecommandTopicFifo;

  corfu::ProtectedVariable<CommanderStandardTelemetry> standardTelemetry;

  corfu::ProtectedVariable<CommanderStandardTelemetry> &getStandardTelemetry() { return standardTelemetry; }

  uint32_t serializeStandardTelemetry(corfu::Slice<uint8_t>& slice) const {
    corfu::Accessor accessor = standardTelemetry.access();
    return accessor->serialize(slice);
  }

  virtual bool handleTelecommandNOP() = 0;
  virtual bool handleTelecommandReboot() = 0;

};

}
