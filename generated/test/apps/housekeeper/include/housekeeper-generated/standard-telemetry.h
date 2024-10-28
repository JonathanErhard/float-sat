#pragma once


#include <corfu/serializable.h>
#include <corfu/slice.h>
#include <corfu/bit-array.h>

#include <stream-bytesex.h>
#include <common-generated/builtin-structs.h>
#include <cstdint>

namespace generated {

struct HousekeeperStandardTelemetry : public corfu::Serializable {
  uint16_t collectInterval{};
  uint16_t iteration{};

  static constexpr std::uint32_t PAYLOAD_SIZE =
    sizeof(collectInterval)+     sizeof(iteration)    ;

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice) const override {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(collectInterval, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(iteration, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice) override {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(collectInterval, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(iteration, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }
};

}
