#pragma once

#include "standard-telemetry.h"



#include <commander-generated/anomaly.h>
#include <commander-generated/config.h>


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

class Commander
  : public corfu::App {

protected:

private:

  void handleTelecommand(const corfu::Telecommand &telecommand) final;


  protected:
        corfu::Telemetry corfu_telemetry;
        static RODOS::Topic<corfu::Anomaly> &corfuAnomalyTopic;
        static RODOS::Topic<corfu::Alive> &corfuAppIsAliveTopic;
        static RODOS::Topic<corfu::Telecommand> &corfuTelecommandTopic;
        static RODOS::Topic<corfu::Telecommand> &corfuUplinkTelecommandTopic;


      virtual void initCommandThread() {}
      virtual void runCommandThread() = 0;


      RODOS::SyncFifo<corfu::Telecommand, 12> corfuUplinkTelecommandTopicFifo;
        RODOS::Subscriber corfuUplinkTelecommandTopicSubscriber{ corfu::uplinkTelecommandTopic, corfuUplinkTelecommandTopicFifo, "Commander" };

      corfu::ProtectedVariable<CommanderStandardTelemetry> standardTelemetry;

  public:
    Commander() : App("Commander", 6) {}
    ~Commander() override = default;

      corfu::ProtectedVariable<CommanderStandardTelemetry> &getStandardTelemetry() { return standardTelemetry; }

      uint32_t serializeStandardTelemetry(corfu::Slice<uint8_t>& slice) const override {
        corfu::Accessor accessor = standardTelemetry.access();
        return accessor->serialize(slice);
      }

  protected:

        virtual bool handleTelecommandNOP() = 0;

        virtual bool handleTelecommandReboot() = 0;


    class CommandThread : public corfu::PeriodicThread<> {
      Commander& app;

    public:
      explicit CommandThread(Commander& app)
      : corfu::PeriodicThread<>(
      1400_ms,
      200_ms,
      "commandThread",
      800),
      app(app) {}

      void init() {
        delayFirstRun();
        app.initCommandThread();
      }

    protected:
      void runIteration() override { app.runCommandThread(); }
    } commandThreadThread{*this};

};

}
