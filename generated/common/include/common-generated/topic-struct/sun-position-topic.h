#pragma once

#include <cstdint>
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



namespace generated {

struct SunPositionTopic {
  float position{};
  float offset{};
};

}
