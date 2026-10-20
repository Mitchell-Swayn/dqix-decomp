#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2248e12; symbol: data_ov031_02248e12.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0600.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248e14; symbol: data_ov031_02248e14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2200.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248e16; symbol: data_ov031_02248e16.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ea00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248e18; symbol: data_ov031_02248e18.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 360006004e00ea00620006007a00ea008e000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290c5c; symbol: data_ov031_02290c5c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage[],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant2[],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant4[],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant3[],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant5[];
extern "C" void WfcUtility_LoadOptionsMenuBackground();
extern "C" void System_CreateCopyAndFinalizeResource(unsigned);
extern "C" void WfcUtility_LoadModeBackgroundAndScheduleUpload(unsigned);
extern "C" void WfcUtility_ShowFormattedMessagePanel(int,int,int);
extern "C" char* Resource_ExpandPackedTableToAllocatedBuffer(unsigned,unsigned);
extern "C" void WfcUtility_CreateCornerSelectionMarkers(unsigned,unsigned,unsigned,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void ConfigureSecondViewPlanes();
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x0222905C; symbol: Graphics_InitializeMappedPaletteScreenAndCallback; size: 0xc8.
// Expands resource 91, configures object mode/palette, applies indexed halfword mapping and installs callback.
extern "C" void Graphics_InitializeMappedPaletteScreenAndCallback(){B(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage,1)=0;WfcUtility_LoadOptionsMenuBackground();System_CreateCopyAndFinalizeResource(16);WfcUtility_LoadModeBackgroundAndScheduleUpload(3);WfcUtility_ShowFormattedMessagePanel(57,-1,0);P(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage,8)=Resource_ExpandPackedTableToAllocatedBuffer(0,91);char* object=P(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage,8);U(object,0)=(U(object,0)&0xfe00ff00)|0xe00084;object=P(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage,8);H(object,4)=(H(object,4)&~0xc00)|0xc00;unsigned offset=B(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage,0)*8;WfcUtility_CreateCornerSelectionMarkers(H(WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant2,offset),H(WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant4,offset),H(WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant3,offset),H(WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant5,offset));WfcUtility_SetMainLoopCallback(ConfigureSecondViewPlanes);}
