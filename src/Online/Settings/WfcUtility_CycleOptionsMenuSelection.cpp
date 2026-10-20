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
extern "C" unsigned short WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant2[],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant4[],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant3[],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant5[];
extern "C" int FastIntModulus(int,int);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_CreateCornerSelectionMarkers(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov031 @ 0x022296B8; symbol: Graphics_CycleThreeEntrySelectionAndApplyAttributes; size: 0x90.
// Original data: arm9/ov031 @ 0x2290c5c; symbol: data_ov031_02290c5c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_CycleOptionsMenuSelection(int direction) {
 if(direction==1)WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage=FastIntModulus(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage+2,3);else WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage=FastIntModulus(WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage+1,3);
 WfcUtility_PlaySequenceArchiveEntry(8);
 unsigned index=WfcUtilityReadOptionsMenuInput_UnknownRoleZeroInitializedStorage*4;WfcUtility_CreateCornerSelectionMarkers(WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant2[index],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant4[index],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant3[index],WfcUtilityReadOptionsMenuInput_UnknownRoleInitializedBytes_Variant5[index]);
}
