#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadMainBG2ResourcesAndSetPriorities(void);
extern "C" void WfcUtility_ShowFormattedMessagePanel(int, int, int);
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive(void);
extern "C" void WfcUtility_ConfigureSecondaryControlsForDisplayMode(unsigned int);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned int);
extern "C" void WfcUtility_CreateAnimatedStatusSprite(unsigned int);
extern "C" void WfcUtility_EnsureWirelessScanBuffer(void);
extern "C" void WfcUtility_InitializeWirelessScanContextAndWaitForReady(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_StartDualDisplayBrightnessTransition(void);
// Original data: arm9/ov031 @ 0x2290cbc; symbol: data_ov031_02290cbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02232024; symbol: InitializeBG2Mode33AndInstallCallback; size: 0x68.
// Clears readiness state, initializes BG2 mode 0x33, sets screen state, configures overlays, then installs callback 0x02232134.
extern "C" void InitializeBG2Mode33AndInstallCallback(void) {
 *(unsigned short *)((char *)&WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage + 2) = 0;
 WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage = 0;
 Graphics_LoadMainBG2ResourcesAndSetPriorities();
 WfcUtility_ShowFormattedMessagePanel(0x33, -1, 0);
 System_ConvertSharedRegionByteToIndexPlusFive();
 WfcUtility_ConfigureSecondaryControlsForDisplayMode(2);
 Graphics_SubmitIndexedConfiguredBuffer(0x33);
 WfcUtility_CreateAnimatedStatusSprite(0);
 WfcUtility_EnsureWirelessScanBuffer();
 WfcUtility_InitializeWirelessScanContextAndWaitForReady();
 WfcUtility_PlaySequenceArchiveEntry(0xa);
 WfcUtility_SetMainLoopCallback(WfcUtility_StartDualDisplayBrightnessTransition);
}
