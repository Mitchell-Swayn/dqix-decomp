#include <globaldefs.h>
ARM
struct SharedThreeWords { unsigned words[3]; };
extern "C" void* volatile WfcUtilityCopyNetworkTaskResult_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02227CB0; symbol: WfcUtility_CopyNetworkTaskResult; size: 0x18.
// Copies the incoming three-word state to the allocation shared by lifecycle callbacks.
extern "C" void WfcUtility_CopyNetworkTaskResult(const SharedThreeWords* source) {
 *(SharedThreeWords*)WfcUtilityCopyNetworkTaskResult_UnknownRoleZeroInitializedStorage=*source;
}
