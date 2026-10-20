#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char);
extern "C" int WfcUtility_IsTouchPressInsideRectangle(unsigned short*);
extern "C" int WfcUtility_AreButtonsPressed(unsigned);
extern "C" bool WfcUtility_AreButtonsPressedOrRepeating(unsigned);
extern "C" void WfcUtility_CreateCornerSelectionMarkers(int,int,int,int);
extern "C" void ToggleDisplaySelectorAndApplyGeometry(int);
// Original data: arm9/ov031 @ 0x2248d8e; symbol: data_ov031_02248d8e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08002000ac00a000b4002000f800a000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
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
extern "C" unsigned short GraphicsHandleTwoRectangleSelectionAndControlInput_UnknownRoleInitializedBytes[],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes[],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant3[],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant2[],WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant4[];
// Original data: arm9/ov031 @ 0x2290c50; symbol: data_ov031_02290c50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" signed char WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02228258; symbol: func_ov031_02228258; size: 0x12C.
// Selects one of two touch rectangles or applies directional display selection.
extern "C" void Graphics_HandleTwoRectangleSelectionAndControlInput(){
int i=0; unsigned short* rect=GraphicsHandleTwoRectangleSelectionAndControlInput_UnknownRoleInitializedBytes;
do {
if(WfcUtility_IsTouchPressInsideRectangle(rect)) {
WfcUtility_LatchBottomButtonSelection(1);
unsigned index=(unsigned char)i;
int a=WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes[index*4],b=WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant3[index*4],c=WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant2[index*4],d=WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant4[index*4];
WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage=i;
WfcUtility_CreateCornerSelectionMarkers(a,b,c,d);return;
}
++i;rect+=4;
}while((unsigned)i<2);
if(WfcUtility_AreButtonsPressed(1)){WfcUtility_LatchBottomButtonSelection(1);return;}
if(WfcUtility_AreButtonsPressed(2)){WfcUtility_LatchBottomButtonSelection(0);return;}
if(WfcUtility_AreButtonsPressedOrRepeating(0x40)){ToggleDisplaySelectorAndApplyGeometry(1);return;}
if(WfcUtility_AreButtonsPressedOrRepeating(0x80)){ToggleDisplaySelectorAndApplyGeometry(3);return;}
if(WfcUtility_AreButtonsPressedOrRepeating(0x20)){ToggleDisplaySelectorAndApplyGeometry(0);return;}
if(WfcUtility_AreButtonsPressedOrRepeating(0x10))ToggleDisplaySelectorAndApplyGeometry(2);
}
