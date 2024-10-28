#pragma once



#include "topic/radio-up-topic.h"
#include "topic/radio-down-topic.h"

#include <transceiver-generated/anomaly.h>
#include <transceiver-generated/config.h>


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

class Transceiver
  : public corfu::App {

protected:

private:

  void handleTelecommand(const corfu::Telecommand &telecommand) final;


  protected:
        corfu::Telemetry corfu_telemetry;
        static RODOS::Topic<corfu::Anomaly> &corfuAnomalyTopic;
        static RODOS::Topic<corfu::Alive> &corfuAppIsAliveTopic;
        static RODOS::Topic<corfu::Telecommand> &corfuUplinkTelecommandTopic;
        static RODOS::Topic<corfu::Telemetry> &corfuStandardTelemetryTopic;
        static RODOS::Topic<corfu::Telemetry> &corfuExtendedTelemetryTopic;
        static RODOS::Topic<corfu::Telecommand> &radioUpTopic;
        static RODOS::Topic<corfu::Telemetry> &radioDownTopic;

        virtual void handleTopicRadioUpTopic(corfu::Telecommand &message) = 0;

      virtual void initTxThread() {}
      virtual void runTxThread() = 0;


      RODOS::SyncFifo<corfu::Telemetry, 24> corfuStandardTelemetryTopicFifo;
        RODOS::Subscriber corfuStandardTelemetryTopicSubscriber{ corfu::standardTelemetryTopic, corfuStandardTelemetryTopicFifo, "Transceiver" };
      RODOS::SyncFifo<corfu::Telemetry, 24> corfuExtendedTelemetryTopicFifo;
        RODOS::Subscriber corfuExtendedTelemetryTopicSubscriber{ corfu::extendedTelemetryTopic, corfuExtendedTelemetryTopicFifo, "Transceiver" };


  public:
    Transceiver() : App("Transceiver", 9) {}
    ~Transceiver() override = default;



  protected:

        virtual bool handleTelecommandNOP() = 0;

    class RadioUpTopicSubscriber
    : public RODOS::SubscriberReceiver<corfu::Telecommand> {
    Transceiver& app;

  public:
  explicit RadioUpTopicSubscriber(Transceiver& app)
    : RODOS::SubscriberReceiver<corfu::Telecommand>(radioUpTopic, "Transceiver"),
      app(app) {}

      void put(corfu::Telecommand& message) override {
        app.handleTopicRadioUpTopic(message);
      }

    } radioUpTopicSubscriber{*this};

    class TxThread : public corfu::PeriodicThread<> {
      Transceiver& app;

    public:
      explicit TxThread(Transceiver& app)
      : corfu::PeriodicThread<>(
      1200_ms,
      100_ms,
      "txThread",
      790),
      app(app) {}

      void init() {
        delayFirstRun();
        app.initTxThread();
      }

    protected:
      void runIteration() override { app.runTxThread(); }
    } txThreadThread{*this};

};

}
