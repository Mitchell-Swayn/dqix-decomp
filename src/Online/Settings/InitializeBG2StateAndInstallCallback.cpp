#include <globaldefs.h>
ARM
extern "C" void LoadBG2ScreenDataAndEnableDisplayPlanes(void);
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned int);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_BeginTimedNoticeDisplayFadeIn(void);
// Original data: arm9/ov031 @ 0x2290c88; symbol: data_ov031_02290c88.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031AdvanceCallbackDelay_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222B450; symbol: InitializeBG2StateAndInstallCallback; size: 0x3C.
// Clears the BG2-ready byte, initializes BG2 data, configures IDs 0x23 and 0x10, then installs the BG2 callback.
extern "C" void InitializeBG2StateAndInstallCallback(void) {
 Ov031AdvanceCallbackDelay_UnknownRoleZeroInitializedStorage = 0;
 LoadBG2ScreenDataAndEnableDisplayPlanes();
 System_ConvertSharedRegionByteToIndexPlusFive();
 Graphics_SubmitIndexedConfiguredBuffer(0x23);
 WfcUtility_PlaySequenceArchiveEntry(0x10);
 WfcUtility_SetMainLoopCallback(WfcUtility_BeginTimedNoticeDisplayFadeIn);
}
