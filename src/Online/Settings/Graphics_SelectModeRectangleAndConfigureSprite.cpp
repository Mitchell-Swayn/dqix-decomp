#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d10; symbol: data_ov031_02290d10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2249394; symbol: data_ov031_02249394.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0201020102000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityCreateSlidingDialog_UnknownRoleInitializedBytes_Variant7[];
// Original data: arm9/ov031 @ 0x22492ea; symbol: data_ov031_022492ea.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00010100000101000001.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilitySetDialogVerticalPosition_UnknownRoleInitializedBytes[][2];
// Original data: arm9/ov031 @ 0x2249308; symbol: data_ov031_02249308.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6c0010006c001000780010007800100078001000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2249364; symbol: data_ov031_02249364.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1000.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilitySetDialogVerticalPosition_UnknownRoleInitializedBytes_Variant5[][4],GraphicsSelectModeRectangleAndConfigureSprite_UnknownRoleInitializedBytes_Variant3[][2];
// Original data: arm9/ov031 @ 0x22492f4; symbol: data_ov031_022492f4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22492f5; symbol: data_ov031_022492f5.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000ff010000ff0100.
// Observed span: 9 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" signed char GraphicsSelectModeRectangleAndConfigureSprite_UnknownRoleInitializedBytes[],GraphicsSelectModeRectangleAndConfigureSprite_UnknownRoleInitializedBytes_Variant2[];
extern "C" void WfcUtility_ApplyDialogButtonSpriteTemplate(int);
extern "C" void WfcUtility_BuildRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
extern "C" int WfcUtility_AreButtonsPressed(unsigned);
extern "C" int WfcUtility_IsTouchPressInsideRectangle(unsigned short*);
#define MODE (*(unsigned char*)(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage+0x1c))
#define CHOICE (*(signed char*)(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage+0x1b))
// Original: arm9/ov031 @ 0x02238000; symbol: func_ov031_02238000; size: 0x15C.
// Selects a mode-specific rectangle or button default and applies its indexed sprite configuration.
extern "C" void Graphics_SelectModeRectangleAndConfigureSprite(void*,void*){
unsigned short rect[4];
for(int i=0;i<WfcUtilityCreateSlidingDialog_UnknownRoleInitializedBytes_Variant7[MODE];++i){
WfcUtility_BuildRectangleFromOriginAndSize(WfcUtilitySetDialogVerticalPosition_UnknownRoleInitializedBytes_Variant5[MODE]+WfcUtilitySetDialogVerticalPosition_UnknownRoleInitializedBytes[MODE][i]*2,GraphicsSelectModeRectangleAndConfigureSprite_UnknownRoleInitializedBytes_Variant3[MODE],rect);
if(WfcUtility_IsTouchPressInsideRectangle(rect)){CHOICE=i;break;}
}
if(WfcUtility_AreButtonsPressed(1))CHOICE=GraphicsSelectModeRectangleAndConfigureSprite_UnknownRoleInitializedBytes[MODE*2];
if(WfcUtility_AreButtonsPressed(2))CHOICE=GraphicsSelectModeRectangleAndConfigureSprite_UnknownRoleInitializedBytes_Variant2[MODE*2];
char* state=WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
for(int i=0;i<WfcUtilityCreateSlidingDialog_UnknownRoleInitializedBytes_Variant7[*(volatile unsigned char*)(state+0x1c)];++i){
if(i==*(signed char*)(state+0x1b)){WfcUtility_ApplyDialogButtonSpriteTemplate(i);return;}
}
*(signed char*)(state+0x1b)=-1;
}
