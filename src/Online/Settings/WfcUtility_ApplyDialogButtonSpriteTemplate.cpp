#include <globaldefs.h>
ARM
extern "C" int WfcUtility_ExpandSpriteCellTemplate(...);
extern "C" int WfcUtility_GetSpriteGroupEntry(...);
extern "C" int WfcUtility_SetSpriteGroupPriority(...);
extern "C" int WfcUtility_SetSpriteGroupPosition(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
// Original data: arm9/ov031 @ 0x22492ea; symbol: data_ov031_022492ea.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00010100000101000001.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilitySetDialogVerticalPosition_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x22492fe; symbol: data_ov031_022492fe.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1b195700231d5900231d.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityCreateSlidingDialog_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/ov031 @ 0x2249364; symbol: data_ov031_02249364.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1000.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilitySetDialogVerticalPosition_UnknownRoleInitializedBytes_Variant5[];
// Original data: arm9/ov031 @ 0x2249366; symbol: data_ov031_02249366.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 84008400840010008400840084000900a7008300a7000900a7008300a7000900a7008300a700.
// Observed span: 38 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityApplyDialogButtonSpriteTemplate_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2290d10; symbol: data_ov031_02290d10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x022383FC; symbol: ConfigureIndexedSpriteFromPackedTables; size: 0xc0.
extern "C" void WfcUtility_ApplyDialogButtonSpriteTemplate(int index){
void* output=(void*)WfcUtility_GetSpriteGroupEntry(P(P(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage,0)+index*4,8),0);unsigned mode=B(P(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage,0),28);WfcUtility_ExpandSpriteCellTemplate(0,B(WfcUtilityCreateSlidingDialog_UnknownRoleInitializedBytes_Variant3+mode*2,index)+1,output);mode=B(P(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage,0),28);unsigned selected=B(WfcUtilitySetDialogVerticalPosition_UnknownRoleInitializedBytes+mode*2,index);WfcUtility_SetSpriteGroupPosition(P(P(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage,0)+index*4,8),-1,H(WfcUtilitySetDialogVerticalPosition_UnknownRoleInitializedBytes_Variant5+mode*8,selected*4),H(WfcUtilityApplyDialogButtonSpriteTemplate_UnknownRoleInitializedBytes+mode*8,selected*4));WfcUtility_SetSpriteGroupPriority(P(P(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage,0)+index*4,8),-1,0);
}
