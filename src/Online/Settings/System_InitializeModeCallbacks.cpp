#include <globaldefs.h>
ARM

extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void WfcUtility_SetConnectionEventCallback(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InitializeSharedCallbackSequence(void);
// Original data: arm9/ov031 @ 0x2290c7c; symbol: data_ov031_02290c7c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0222AE38; symbol: func_ov031_0222ae38; size: 0x5C.
extern "C" void System_InitializeModeCallbacks(int mode) {
    WfcUtility_StopSequenceImmediately();
    if (mode == 0) {
        SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage[0] = 1;
        WfcUtility_PlaySequenceArchiveEntry(0x10);
    } else {
        SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage[0] = 2;
        WfcUtility_PlaySequenceArchiveEntry(0x12);
    }
    WfcUtility_SetConnectionEventCallback(0);
    WfcUtility_SetMainLoopCallback(System_InitializeSharedCallbackSequence);
}
