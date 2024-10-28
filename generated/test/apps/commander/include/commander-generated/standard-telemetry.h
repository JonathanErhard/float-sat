#pragma once


#include <corfu/serializable.h>
#include <corfu/slice.h>
#include <corfu/bit-array.h>

#include <stream-bytesex.h>
#include <common-generated/builtin-structs.h>
#include <cstdint>

namespace generated {

struct CommanderStandardTelemetry : public corfu::Serializable {
  uint16_t cmdCounter{};
  uint16_t lastCmdReceivedAt{};

  static constexpr std::uint32_t PAYLOAD_SIZE =
    sizeof(cmdCounter)+     sizeof(lastCmdReceivedAt)    ;

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice) const override {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(cmdCounter, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(lastCmdReceivedAt, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice) override {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(cmdCounter, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(lastCmdReceivedAt, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }
};

}
