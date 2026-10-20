#include <globaldefs.h>
ARM
extern "C" int Wireless_RequestDownloadSessionShutdown();
extern "C" void WfcUtility_RequestTaskRemoval(unsigned, void*, unsigned char*, unsigned);
// Original data: arm9/ov031 @ 0x2290c44; symbol: data_ov031_02290c44.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02227804; symbol: func_ov031_02227804; size: 0x3C.
extern "C" void System_ActivateGlobalControlForObject(void* object) {
    if (!Wireless_RequestDownloadSessionShutdown()) return;
    unsigned char* control = (unsigned char*)WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage;
    unsigned char* region = control + 0x1e000;
    region[0x2a1] = 1;
    WfcUtility_RequestTaskRemoval(0, object, region, 1);
}
