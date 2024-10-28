#pragma once

#include <corfu/anomaly.h>
#include <corfu/slice.h>
#include <corfu/tele/node-id.h>
#include <corfu/bit-array.h>
#include "math.h" // for sin, sqrt, etc
#include "stdint.h"

#include "rodos-result.h"

#include "matlib/api/math_support.h"
#include "matlib/api/typedefs.h"
#include "matlib/api/matrix.h"
#include "matlib/api/vector.h"
#include "matlib/api/quaternion.h"
#include "matlib/api/ypr.h"
#include "matlib/api/angleaxis.h"
#include "matlib/api/coordinateframe3d.h"
#include "matlib/api/polar.h"
#include "matlib/api/complex.h"
#include "matlib/api/homogenous.h"


#include <stream-bytesex.h>

using namespace RODOS;

#include <common-generated/builtin-structs.h>

#include <cstdint>

namespace generated {

struct SetCollectInterval {
  uint16_t intervalInSeconds{};

  static constexpr std::uint32_t PAYLOAD_SIZE =
    sizeof(intervalInSeconds)    ;

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice) const {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(intervalInSeconds, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(intervalInSeconds, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }
};

}
