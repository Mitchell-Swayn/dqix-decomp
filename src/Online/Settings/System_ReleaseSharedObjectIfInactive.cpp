#include <globaldefs.h>
ARM

extern "C" void Network_ShutdownQueueSessionAndWait(void *);
extern "C" void Graphics_InitializeDisplayPageFromFieldSnapshot(void *);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original data: arm9/ov031 @ 0x2250c04; symbol: data_ov031_02250c04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeNetworkRequest_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2250c08; symbol: data_ov031_02250c08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *SystemReleaseSharedObjectIfInactive_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x02226F18; symbol: func_ov031_02226f18; size: 0x50.
extern "C" void System_ReleaseSharedObjectIfInactive(void *context) {
    Network_ShutdownQueueSessionAndWait(context);
    if (context != 0) {
        void *object = *(void **)(WfcUtilityInitializeNetworkRequest_UnknownRoleZeroInitializedStorage + 4);
        if (*((unsigned char *)object + 0x116) == 0 && WfcUtilityInitializeNetworkRequest_UnknownRoleZeroInitializedStorage[0] == 1) {
            Graphics_InitializeDisplayPageFromFieldSnapshot((char *)object + 0x117);
        }
    }
    WfcUtility_FreeAllocationAndClearPointer(SystemReleaseSharedObjectIfInactive_UnknownRoleZeroInitializedStorage);
}
