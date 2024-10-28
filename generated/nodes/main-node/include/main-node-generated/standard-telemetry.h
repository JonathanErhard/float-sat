#pragma once

#include <housekeeper-generated/standard-telemetry.h>
#include <commander-generated/standard-telemetry.h>

#include <corfu/telemetry-payload.h>
#include <corfu/tele/telemetry.h>

namespace generated {

struct StandardTelemetry : public corfu::TelemetryPayload {
    HousekeeperStandardTelemetry housekeeperStandardTelemetry;
    CommanderStandardTelemetry commanderStandardTelemetry;

    static constexpr std::uint32_t PAYLOAD_SIZE =
      HousekeeperStandardTelemetry::PAYLOAD_SIZE
+       CommanderStandardTelemetry::PAYLOAD_SIZE
+       0
;

      static_assert(PAYLOAD_SIZE <= corfu::Telemetry::MAX_PAYLOAD_BUFFER_SIZE , "NODE standardTM payload size exceeds max telemetry payload size! "
                                                                                "This will cause an onboard software runtime error and the payload will be truncated.");

    StandardTelemetry() : corfu::TelemetryPayload(1, PAYLOAD_SIZE) {}

    void setTelemetry(const HousekeeperStandardTelemetry& housekeeperStandardTelemetry) {
      this->housekeeperStandardTelemetry = housekeeperStandardTelemetry;
    }
    void setTelemetry(const CommanderStandardTelemetry& commanderStandardTelemetry) {
      this->commanderStandardTelemetry = commanderStandardTelemetry;
    }

    RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice) const override {
      std::uint32_t startInBytes = 0;

      {
        RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
        RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
        startInBytes += housekeeperStandardTelemetry.serialize(subSliceResult.val);
      }
      {
        RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
        RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
        startInBytes += commanderStandardTelemetry.serialize(subSliceResult.val);
      }

      return startInBytes;
    }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice) override {
    std::uint32_t startInBytes = 0;

    {
      RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
      RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
      startInBytes += housekeeperStandardTelemetry.deserialize(subSliceResult.val);
    }
    {
      RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
      RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
      startInBytes += commanderStandardTelemetry.deserialize(subSliceResult.val);
    }

    return startInBytes;
  }
};

}
