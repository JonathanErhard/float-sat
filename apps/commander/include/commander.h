#pragma once

#include <commander-generated/commander.h>


class Commander : public generated::Commander {

    uint16_t lastCmdIndex           = 0u;
    uint16_t lastCmdReceivedTime     = 0u;

    uint16_t iterations = 0;

    void updateStdTM();

    protected:
        bool isCheckPaused = false;
        bool handleTelecommandNOP() override;
        bool handleTelecommandReboot() override;

    public:
        void runCommandThread() override;

};