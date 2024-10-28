#pragma once

#include <corfu/anomaly.h>
#include <corfu/slice.h>
#include <corfu/tele/node-id.h>
#include <corfu/bit-array.h>
#include <corfu/app.h>

#include <stream-bytesex.h>
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

#include <cstdint>
using namespace RODOS;

namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::AngleAxis &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::AngleAxis &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::AngleAxis_F &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::AngleAxis_F &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Complex &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Complex &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Complex_F &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Complex_F &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::CoordinateFrame3D &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::CoordinateFrame3D &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::CoordinateFrame3D_F &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::CoordinateFrame3D_F &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Matrix3D_F &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Matrix3D_F &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Quaternion &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Quaternion &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Quaternion_F &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Quaternion_F &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Vector3D &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Vector3D &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Vector3D_F &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Vector3D_F &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Vector6D &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Vector6D &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Vector6D_F &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, RODOS::Vector6D_F &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const corfu::Alive &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, corfu::Alive &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const corfu::Anomaly &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, corfu::Anomaly &thisStruct);
}
namespace generated {
  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const corfu::NodeId &thisStruct);
  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice, corfu::NodeId &thisStruct);
}
