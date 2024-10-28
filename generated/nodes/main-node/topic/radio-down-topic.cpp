
#include <corfu/anomaly.h>
#include <corfu/tele/file-segment.h>
#include <corfu/tele/telecommand.h>
#include <corfu/tele/telemetry.h>
#include <corfu/anomaly.h>

#include <topic.h>

#include <cstdint>

namespace generated {

RODOS::Topic<corfu::Telemetry> radioDownTopic(2447, "radioDownTopic");

} // namespace generated
