#include <globaldefs.h>
ARM
struct PendingContextCalls { unsigned int first; unsigned int second; };
// Original data: arm9/ov031 @ 0x224e5dc; symbol: data_ov031_0224e5dc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" struct PendingContextCalls Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage;
extern "C" void OnlineMemory_FreeTagged(int, unsigned int, int);
// Original: arm9/ov031 @ 0x022166B4; symbol: func_ov031_022166b4; size: 0x5C.
extern "C" void WirelessBeaconScan_ReleaseSelectionWorkspaces(void) {
    if (Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage.second != 0) {
        OnlineMemory_FreeTagged(1, Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage.second, 0);
        Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage.second = 0;
    }
    if (Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage.first != 0) {
        OnlineMemory_FreeTagged(1, Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage.first, 0);
        Ov031SetGlobalFieldToFour_UnknownRoleZeroInitializedStorage.first = 0;
    }
}
