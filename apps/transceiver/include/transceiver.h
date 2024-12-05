#pragma once

#include <transceiver-generated/transceiver.h>

#include <gateway/gateway.h>
#include <gateway/linkinterfaceudp.h>
#include <gateway/linkinterfaceuart.h>
#include <gateway/networkmessage.h>
#include <hal/hal_uart.h>
#include <hal/hal_gpio.h>
#include <hal/udp.h>



class Transceiver: public generated::Transceiver {

private:
    /*
     * using UDP
     */
    // RODOS::UDPInOut         udpio { config::transceiver::UPLINK_PORT, config::transceiver::DOWNLINK_PORT, "localhost" };
    // RODOS::LinkinterfaceUDP link  { &udpio };

    /*
     * using UART
     */
    //RODOS::HAL_UART uart_egse {RODOS::UART_IDX3,RODOS::GPIO_056,RODOS::GPIO_057}; // TM AND TC THROUGH PROGRAMMING WIRE
    RODOS::HAL_UART uart_egse {RODOS::UART_IDX2,RODOS::GPIO_053,RODOS::GPIO_054}; // TM AND TC THROUGH BLUETOOTH CONNECTOR

    RODOS::LinkinterfaceUART link { &uart_egse, 115200 };

    RODOS::Gateway          gw    { &link, true };
    RODOS::TopicListReport  topics;

protected:
    void handleTopicRadioUpTopic(corfu::Telecommand &message) override;
    bool handleTelecommandNOP() override;

public:
    void initialize() override;
    void runTxThread() override;

};
