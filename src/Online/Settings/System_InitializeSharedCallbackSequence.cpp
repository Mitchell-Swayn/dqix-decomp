#include <globaldefs.h>
ARM

extern "C" void* WfcUtility_ScheduleConnectionActivation(void);
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned short);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_BeginContextPromptFadeOut(void);
// Original data: arm9/ov031 @ 0x2290c7c; symbol: data_ov031_02290c7c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0222AC88; symbol: func_ov031_0222ac88; size: 0x38.
extern "C" void System_InitializeSharedCallbackSequence(void) {
    if (SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage[0] == 0) {
        WfcUtility_ScheduleConnectionActivation();
    }
    WfcUtility_DisableBottomButtonTouch();
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcUtility_BeginContextPromptFadeOut);
}
