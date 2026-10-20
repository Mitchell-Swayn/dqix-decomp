#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cac; symbol: data_ov031_02290cac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage;
extern "C" void Graphics_LoadXb4MultiScreenAndSetPriorities();
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive();
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void WfcUtility_CreateAnimatedStatusSprite(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcMultiScreen_StartMainDisplayBrightnessTransition();
// Original: arm9/ov031 @ 0x02231140; symbol: InitializeControlByte25AndInstallCallback; size: 0x3C.
// Clears the overlay control byte, runs setup helpers including selector 0x25 and value 1, then installs the next callback.
extern "C" void InitializeControlByte25AndInstallCallback() {
    WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage = 0;
    Graphics_LoadXb4MultiScreenAndSetPriorities();
    System_ConvertSharedRegionByteToIndexPlusFive();
    Graphics_SubmitIndexedConfiguredBuffer(0x25);
    WfcUtility_CreateAnimatedStatusSprite(1);
    WfcUtility_SetMainLoopCallback(WfcMultiScreen_StartMainDisplayBrightnessTransition);
}
