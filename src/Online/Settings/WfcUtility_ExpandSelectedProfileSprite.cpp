#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2249082; symbol: data_ov031_02249082.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0800.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2249084; symbol: data_ov031_02249084.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 30005a003000ac0030000c0058005e005800b0005800.
// Observed span: 22 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes[],WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes_Variant2[];
extern "C" void* WfcUtility_GetSpriteGroupEntry(void*,int);
extern "C" void WfcUtility_ExpandSpriteCellTemplate(unsigned,unsigned,void*);
extern "C" void WfcUtility_SetSpriteGroupPosition(void*,int,unsigned,unsigned);
extern "C" void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);
// Original: arm9/ov031 @ 0x02232F58; symbol: Graphics_ExpandSelectedSpriteAndSetPriorityThree; size: 0x90.
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_ExpandSelectedProfileSprite() {
 int index=ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[0]-4;
 WfcUtility_ExpandSpriteCellTemplate(0,50,WfcUtility_GetSpriteGroupEntry(*(void**)(*(char**)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage+4)+16+index*4),0));
 WfcUtility_SetSpriteGroupPosition(*(void**)(*(char**)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage+4)+16+index*4),-1,WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes[(index+3)*2],WfcUtilityExpandSelectedProfileSprite_UnknownRoleInitializedBytes_Variant2[(index+3)*2]);
 WfcUtility_SetSpriteGroupPriority(*(void**)(*(char**)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage+4)+16+index*4),-1,3);
}
