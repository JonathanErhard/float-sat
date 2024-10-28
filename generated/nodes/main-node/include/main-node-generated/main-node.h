#pragma once

#include "standard-telemetry.h"

#include "housekeeper.h"
#include "commander.h"
#include "transceiver.h"

#include <corfu/app.h>
#include <corfu/node.h>
#include <corfu/array.h>
#include <corfu/tele/telecommand.h>
#include <corfu/telemetry-payload.h>

#include <initiator.h>

#include <cstddef>

namespace generated {

class MainNode : public corfu::Node {
    ::Housekeeper housekeeper;
    ::Commander commander;
    ::Transceiver transceiver;

    corfu::Array<corfu::App*, 3> apps = {
        &housekeeper,        &commander,        &transceiver    };

    void setHardwareId() override;

  public:
    MainNode() : Node(apps, 255, "MAIN-NODE") {}
    ~MainNode() override = default;
};

}
