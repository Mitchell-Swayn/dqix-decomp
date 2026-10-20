#include <globaldefs.h>
ARM
extern "C" int Network_StartExtendedScan(void* fn, void* object);
// Original data: arm9/ov031 @ 0x2290cf8; symbol: data_ov031_02290cf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage;
extern "C" int Network_HandleType26ScanReply();
// Original: arm9/ov031 @ 0x022358B4; symbol: func_ov031_022358b4; size: 0x34.
extern "C" int GameState_IsCallbackStateReady(void) {
    int result = Network_StartExtendedScan((void*)Network_HandleType26ScanReply,
        (char*)WfcUtilityFreeWirelessScanBufferWhenInactive_UnknownRoleZeroInitializedStorage + 0x1648);
    return result == 2;
}
