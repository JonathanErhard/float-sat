#pragma once

#include "standard-telemetry.h"

#include "telecommand/set-collect-interval.h"


#include <housekeeper-generated/anomaly.h>
#include <housekeeper-generated/config.h>


#include <common-generated/anomaly.h>

#include <corfu/app.h>
#include <corfu/node.h>
#include <corfu/fifo-thread.h>
#include <corfu/global-topics.h>
#include <corfu/periodic-thread.h>
#include <corfu/protected-variable.h>
#include <corfu/tele/telecommand.h>
#include <corfu/time-literal.h>

#include <fifo.h>
#include <subscriber.h>


namespace generated {

class Housekeeper
  : public corfu::App {

protected:

private:

  void handleTelecommand(const corfu::Telecommand &telecommand) final;


  protected:
        corfu::Telemetry corfu_telemetry;
        static RODOS::Topic<corfu::Alive> &corfuAppIsAliveTopic;
        static RODOS::Topic<corfu::Telemetry> &corfuStandardTelemetryTopic;
        static RODOS::Topic<corfu::Telemetry> &corfuExtendedTelemetryTopic;


      virtual void initCollector() {}
      virtual void runCollector() = 0;



      corfu::ProtectedVariable<HousekeeperStandardTelemetry> standardTelemetry;

  public:
    Housekeeper() : App("Housekeeper", 11) {}
    ~Housekeeper() override = default;

      corfu::ProtectedVariable<HousekeeperStandardTelemetry> &getStandardTelemetry() { return standardTelemetry; }

      uint32_t serializeStandardTelemetry(corfu::Slice<uint8_t>& slice) const override {
        corfu::Accessor accessor = standardTelemetry.access();
        return accessor->serialize(slice);
      }

  protected:

        virtual bool handleTelecommandNOP() = 0;
        virtual bool handleTelecommandSetCollectInterval(const SetCollectInterval& setCollectInterval) = 0;


    class Collector : public corfu::PeriodicThread<> {
      Housekeeper& app;

    public:
      explicit Collector(Housekeeper& app)
      : corfu::PeriodicThread<>(
      1100_ms,
      200_ms,
      "Collector",
      500),
      app(app) {}

      void init() {
        delayFirstRun();
        app.initCollector();
      }

    protected:
      void runIteration() override { app.runCollector(); }
    } collectorThread{*this};

};

}
