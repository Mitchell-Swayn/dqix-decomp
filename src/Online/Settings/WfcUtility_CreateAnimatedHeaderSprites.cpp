#include "globaldefs.h"
#include "std_library_functions.h"
// Original: arm9/ov031 @ 0x0223690c; symbol: CreateFiveModeSpritesAndInstallSlideCallback.
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
struct SpritePosition{unsigned short x,y;};struct List;struct Object;extern unsigned char*volatile AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[];extern unsigned char WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes[],WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant2[];extern unsigned short WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant3[];extern "C" void* Memory_AllocateZeroedBlock(unsigned);extern "C" void*WfcUtility_CreateSpriteGroupFromCellTemplate(unsigned,unsigned,unsigned);extern "C" void WfcUtility_SetSpriteGroupPriority(List*,int,unsigned),WfcUtility_SetSpriteGroupPosition(void*,unsigned,unsigned,unsigned),Graphics_SetObjectModeAndPalette(Object*,int,int,int),WfcUtility_CreateTaskWithBorrowedContext(void*,void*,void*,void*),WfcUtility_SlideHeaderLeadingGroupToLeftAnchor(),WfcUtility_LoadModeBackgroundAndScheduleUpload(unsigned);extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" ARM void WfcUtility_CreateAnimatedHeaderSprites(unsigned mode){volatile unsigned savedMode=mode;unsigned char*allocation=(unsigned char*)((void*(*)(unsigned,int))Memory_AllocateZeroedBlock)(28,4);unsigned offset=savedMode*5;AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1]=allocation;unsigned char*resources=WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes+offset,*palettes=WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant2+offset;int i=0;do{((void**)AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1])[i]=WfcUtility_CreateSpriteGroupFromCellTemplate(1,*resources++,1);WfcUtility_SetSpriteGroupPriority((List*)((void**)AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1])[i],-1,0);WfcUtility_SetSpriteGroupPosition(((void**)AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1])[i],-1,(unsigned)-42,((SpritePosition*)((unsigned char*)WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant3+i*4))->y);Graphics_SetObjectModeAndPalette((Object*)((void**)AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1])[i],-1,0,*palettes++);i++;}while(i<5);*(unsigned*)(AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1]+20)=((unsigned(*)(int,void(*)(),int,int))WfcUtility_CreateTaskWithBorrowedContext)(0,WfcUtility_SlideHeaderLeadingGroupToLeftAnchor,0,120);WfcUtility_LoadModeBackgroundAndScheduleUpload(savedMode);WfcUtility_PlaySequenceArchiveEntry(13);}