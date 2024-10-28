#pragma once

#include "anomaly.h"
#include "config.h"




#include "topic/radio-up-topic.h"
#include "topic/radio-down-topic.h"

#include <corfu/protected-variable.h>
#include <corfu/test/app.h>

#include <fifo.h>
#include <subscriber.h>

namespace generated {

class Transceiver : public corfu::test::App {
public:

  corfu::test::Topic<corfu::Anomaly> corfuAnomalyTopic;
  corfu::test::Topic<corfu::Alive> corfuAppIsAliveTopic;
  corfu::test::Topic<corfu::Telecommand> corfuUplinkTelecommandTopic;
  corfu::test::Topic<corfu::Telemetry> corfuStandardTelemetryTopic;
  corfu::test::Topic<corfu::Telemetry> corfuExtendedTelemetryTopic;
  corfu::test::Topic<corfu::Telecommand> radioUpTopic;
  corfu::test::Topic<corfu::Telemetry> radioDownTopic;

  virtual void handleTopicRadioUpTopic(corfu::Telecommand &message) = 0;

  virtual void initTxThread() {}
  virtual void runTxThread() = 0;

  RODOS::SyncFifo<corfu::Telemetry, 24> corfuStandardTelemetryTopicFifo;
  RODOS::SyncFifo<corfu::Telemetry, 24> corfuExtendedTelemetryTopicFifo;




  virtual bool handleTelecommandNOP() = 0;

};

}
