//
// Created by Moritz Arbab on 18.10.23.
// auto-generating app-ids.h
//

#pragma once

#include "corfu/map.h"

namespace corfu {
    const uint8_t NUMBER_OF_APPS = 3;
    inline const corfu::Map<uint8_t, const char*, NUMBER_OF_APPS> appMap {
        { 6 , "COMMANDER" },
        { 11 , "HOUSEKEEPER" },
        { 9 , "TRANSCEIVER" },
    };
}
