#pragma once

#include "corfu/tele/node-id.h"

namespace NodeIDs {
      static constexpr corfu::NodeId MAIN_NODE = { 255, 0 };

      static constexpr corfu::NodeId MAIN_NODE_ID0 = { 255, 1 };

  static constexpr uint32_t length() {return 1;}
}
