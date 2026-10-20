#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x22490d2; symbol: data_ov031_022490d2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0600.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22490d4; symbol: data_ov031_022490d4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1e00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22490d6; symbol: data_ov031_022490d6.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4600.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22490d8; symbol: data_ov031_022490d8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 480058001e0098004800aa001e00ea00480006007600ea00920009005400430070005b00540095007000ad005400e70070000000.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes[],WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes_Variant3[],WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes_Variant2[],WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes_Variant4[];
extern "C" void WfcUtility_CreateCornerSelectionMarkers(unsigned,unsigned,unsigned,unsigned);
extern "C" void WfcUtility_CreatePairedSelectionMarkers(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov031 @ 0x02232CE8; symbol: ApplyIndexedTransitionCoordinates; size: 0x7c.
// Selects four halfword coordinate fields from eight-byte indexed rows; alternate call after index3.
extern "C" void WfcUtility_PositionProfileSelectionHighlight(){
 unsigned index=ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage;
 if(index<4)WfcUtility_CreateCornerSelectionMarkers(WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes[index*4],WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes_Variant3[index*4],WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes_Variant2[index*4],WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes_Variant4[index*4]);
 else WfcUtility_CreatePairedSelectionMarkers(0,WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes[index*4],WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes_Variant3[index*4],WfcUtilityPositionProfileSelectionHighlight_UnknownRoleInitializedBytes_Variant2[index*4]);
}
