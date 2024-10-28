#include "builtin-structs.h"
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::AngleAxis &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.u);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.phi, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::AngleAxis &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.u);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.phi, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::AngleAxis_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.u);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.phi, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::AngleAxis_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.u);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.phi, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Complex &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.Re, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.Im, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Complex &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.Re, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.Im, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Complex_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.Re, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.Im, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Complex_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.Re, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.Im, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::CoordinateFrame3D &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.x);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.y);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.z);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.origin);
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::CoordinateFrame3D &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.x);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.y);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.z);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.origin);
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::CoordinateFrame3D_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.x);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.y);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.z);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.origin);
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::CoordinateFrame3D_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.x);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.y);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.z);
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.origin);
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Matrix3D_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          for(uint32_t i = 0; i < 3; ++i) {
              RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
              RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
                startInBytes += BasicSerializers::serialize(thisStruct.r[i], reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
            }
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Matrix3D_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          for(uint32_t i = 0; i < 3; ++i) {
            RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
            RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
              startInBytes += BasicSerializers::deserialize(thisStruct.r[i], reinterpret_cast<const char*> (subSliceResult.val.getRawDataPointer()));
          }
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Quaternion &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.q0, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.q);
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Quaternion &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.q0, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.q);
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Quaternion_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.q0, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
            startInBytes += generated::serialize( subSliceResult.val, thisStruct.q);
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Quaternion_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.q0, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += deserialize(subSliceResult.val, thisStruct.q);
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Vector3D &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.x, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.y, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.z, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Vector3D &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.x, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.y, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.z, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Vector3D_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.x, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.y, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.z, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Vector3D_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.x, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.y, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.z, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Vector6D &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          for(uint32_t i = 0; i < 6; ++i) {
              RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
              RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
                startInBytes += BasicSerializers::serialize(thisStruct.v[i], reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
            }
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Vector6D &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          for(uint32_t i = 0; i < 6; ++i) {
            RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
            RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
              startInBytes += BasicSerializers::deserialize(thisStruct.v[i], reinterpret_cast<const char*> (subSliceResult.val.getRawDataPointer()));
          }
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const RODOS::Vector6D_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          for(uint32_t i = 0; i < 6; ++i) {
              RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
              RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
                startInBytes += BasicSerializers::serialize(thisStruct.v[i], reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
            }
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,RODOS::Vector6D_F &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          for(uint32_t i = 0; i < 6; ++i) {
            RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
            RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
              startInBytes += BasicSerializers::deserialize(thisStruct.v[i], reinterpret_cast<const char*> (subSliceResult.val.getRawDataPointer()));
          }
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const corfu::Alive &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.id, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.timeout, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,corfu::Alive &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.id, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.timeout, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const corfu::Anomaly &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.id, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.isCritical, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.reportTime, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,corfu::Anomaly &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.id, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.isCritical, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.reportTime, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
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



namespace generated {

  RODOS::Result<std::uint32_t> serialize([[maybe_unused]] corfu::Slice<uint8_t>& slice, const corfu::NodeId &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.nodeTypeId, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::serialize(thisStruct.hardwareId, reinterpret_cast<char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

  RODOS::Result<std::uint32_t> deserialize([[maybe_unused]] const corfu::Slice<const uint8_t>& slice,corfu::NodeId &thisStruct) {
    std::uint32_t startInBytes = 0;

      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.nodeTypeId, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
      {
          RODOS::Result subSliceResult = slice.getTailSubSlice(startInBytes);
          RODOS_ASSERT_IFNOT_RETURN(subSliceResult.isOk(), RODOS::ErrorCode::MEMORY);
          startInBytes += BasicSerializers::deserialize(thisStruct.hardwareId, reinterpret_cast<const char*>(subSliceResult.val.getRawDataPointer()));
      }
    return startInBytes;
  }

}
