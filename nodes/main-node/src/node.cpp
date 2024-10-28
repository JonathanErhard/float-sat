//generated using CreateApp.sh

#include "main-node-generated/main-node.h"
#include "rodos.h"

namespace RODOS{
	extern int32_t myNodeNr;
}

void generated::MainNode::setHardwareId() {
	nodeId.hardwareId = 0x01; //FIXME: Change hardware-id according to your design!
	RODOS::myNodeNr = nodeId.nodeTypeId | nodeId.hardwareId;
	RODOS::PRINTF(SCREEN_YELLOW "\tNodeID = { 0x%0x, 0x%0x }\n" SCREEN_RESET,  nodeId.nodeTypeId, nodeId.hardwareId);
}
