#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c80; symbol: data_ov031_02290c80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_LoadThreeBGAssetsAndSetPriorities();
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive();
extern "C" void WfcUtility_ShowFormattedMessagePanel(int, int, int);
extern "C" void WfcUtility_ConfigureSecondaryControlsForDisplayMode(int);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void WfcUtility_CreateAnimatedStatusSprite(int);
extern "C" void WfcUtility_InitializeNetworkRequest();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Graphics_ConfigureDisplayPlanesAndInstallCallback();
// Original: arm9/ov031 @ 0x0222AEB4; symbol: InitializeSharedDisplayStateAndInstallCallback; size: 0x60.
// Clears shared halfword +2, runs the listed display/system setup with selectors 0x36, 2, 0x22, 0, 0xB, then installs callback 0x0222AFBC.
extern "C" void InitializeSharedDisplayStateAndInstallCallback(void) {
    WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[1] = 0;
    Graphics_LoadThreeBGAssetsAndSetPriorities();
    System_ConvertSharedRegionByteToIndexPlusFive();
    WfcUtility_ShowFormattedMessagePanel(0x36, 0x36 - 0x37, 0);
    WfcUtility_ConfigureSecondaryControlsForDisplayMode(2);
    Graphics_SubmitIndexedConfiguredBuffer(0x22);
    WfcUtility_CreateAnimatedStatusSprite(0);
    WfcUtility_InitializeNetworkRequest();
    WfcUtility_PlaySequenceArchiveEntry(0xb);
    WfcUtility_SetMainLoopCallback(Graphics_ConfigureDisplayPlanesAndInstallCallback);
}
