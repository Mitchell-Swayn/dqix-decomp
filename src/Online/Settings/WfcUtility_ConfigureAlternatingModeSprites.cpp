#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224924c; symbol: data_ov031_0224924c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010005000604000200060400050003.
// Observed span: 15 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224925b; symbol: data_ov031_0224925b.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 020103010305010401050701070106.
// Observed span: 15 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224926a; symbol: data_ov031_0224926a.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 20002100500030006800210098003000b00021000000.
// Observed span: 22 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290d04; symbol: data_ov031_02290d04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern unsigned char WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes[],WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant2[];struct Pair{unsigned short x,y;};extern Pair WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant3[];extern char AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[];void* WfcUtility_GetSpriteGroupEntry(void*,int);void WfcUtility_ExpandSpriteCellTemplate(unsigned,unsigned,void*);void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);void WfcUtility_SetSpriteGroupPosition(void*,int,unsigned,unsigned);void Graphics_SetObjectModeAndPalette(void*,int,int,int);void WfcUtility_LoadModeBackgroundAndScheduleUpload(unsigned);}
// Original: arm9/ov031 @ 0x02236EA0; symbol: Graphics_ConfigureThreeAlternatingSprites; size: 0xc8.
extern "C" void WfcUtility_ConfigureAlternatingModeSprites(unsigned index){int i=0;unsigned char* entries=WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes+index*5;unsigned char* palettes=WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant2+index*5;do{WfcUtility_ExpandSpriteCellTemplate(1,*entries,WfcUtility_GetSpriteGroupEntry((*(void***)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage+4))[i],0));entries+=2;WfcUtility_SetSpriteGroupPriority((*(void***)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage+4))[i],-1,0);WfcUtility_SetSpriteGroupPosition((*(void***)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage+4))[i],-1,WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant3[i].x,WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant3[i].y);Graphics_SetObjectModeAndPalette((*(void***)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage+4))[i],-1,0,*palettes);palettes+=2;i+=2;}while(i<5);WfcUtility_LoadModeBackgroundAndScheduleUpload(index);}
