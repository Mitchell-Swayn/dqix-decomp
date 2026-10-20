#include <globaldefs.h>
ARM
extern "C" void WfcUtility_LoadMainMenuBackground();
extern "C" void System_CreateCopyAndFinalizeResource(unsigned);
extern "C" void WfcUtility_ShowFormattedMessagePanel(int,int,int);
extern "C" void WfcUtility_LoadModeBackgroundAndScheduleUpload(unsigned);
// Original data: arm9/ov031 @ 0x2290c50; symbol: data_ov031_02290c50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2248d9e; symbol: data_ov031_02248d9e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0600.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248da0; symbol: data_ov031_02248da0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1e00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248da2; symbol: data_ov031_02248da2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9e00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248da4; symbol: data_ov031_02248da4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9200b2001e00ea009200.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes[],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant3[],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant2[],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant4[];
extern "C" void WfcUtility_CreateCornerSelectionMarkers(unsigned,unsigned,unsigned,unsigned);
extern "C" void WfcUtility_FadeInMainMenu();
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
// Original: arm9/ov031 @ 0x02228024; symbol: InitializeIndexedResourceTransition; size: 0x7c.
// Creates resource0, configures resource4 and indexed halfword transition parameters, then installs callback.
extern "C" void WfcUtility_InitializeMainMenu(){
 WfcUtility_LoadMainMenuBackground();System_CreateCopyAndFinalizeResource(0);
 WfcUtility_ShowFormattedMessagePanel(0x2e,-1,0);WfcUtility_LoadModeBackgroundAndScheduleUpload(4);
 unsigned i=WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage;
 WfcUtility_CreateCornerSelectionMarkers(WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes[i*4],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant3[i*4],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant2[i*4],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant4[i*4]);
 WfcUtility_SetMainLoopCallback(WfcUtility_FadeInMainMenu);
}
