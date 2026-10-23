#include <globaldefs.h>
ARM
#pragma force_active on
struct StatusSpriteAttributes { unsigned position; unsigned short attributes; unsigned short padding; };
struct AnimatedStatusSprite { void* task; StatusSpriteAttributes* sprite; unsigned char kind; unsigned char padding[3]; };
extern "C" {
// Original data: arm9/ov031 @ 0x02250ba4; symbol: data_ov031_02250ba4; initially-zero status-sprite owner pointer.
extern AnimatedStatusSprite* WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x02248910; symbol: data_ov031_02248910; palette selection bytes.
extern const unsigned char WfcUtilityCreateAnimatedStatusSprite_UnknownRoleInitializedBytes[];
void* Memory_AllocateZeroedBlock(unsigned,unsigned);
void* Resource_ExpandPackedTableToAllocatedBuffer(unsigned,unsigned);
void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void*,void*,unsigned);
void AdvanceAnimatedSpriteFrameAndAttributes();
}
// Original: arm9/ov031 @ 0x02222b0c; symbol: func_ov031_02222b0c; size: 0xd0.
// Allocates the animated status sprite, selects its palette and position, and schedules its frame callback.
extern "C" void WfcUtility_CreateAnimatedStatusSprite(unsigned kind)
{
    WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage=(AnimatedStatusSprite*)Memory_AllocateZeroedBlock(12,4);
    WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->kind=kind;
    WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->sprite=(StatusSpriteAttributes*)Resource_ExpandPackedTableToAllocatedBuffer(0,0x47);
    unsigned palette=WfcUtilityCreateAnimatedStatusSprite_UnknownRoleInitializedBytes[kind];
    StatusSpriteAttributes* sprite=WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->sprite;
    sprite->attributes=(sprite->attributes&~0xc00)|0x400;
    sprite=WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->sprite;
    sprite->position&=~0xc00u;
    sprite->attributes=(sprite->attributes&~0xf000)|(palette<<12);
    sprite=WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->sprite;
    sprite->position=(sprite->position&0xfe00ff00)|0x00e6008b;
    WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage->task=WfcUtility_CreateTaskWithBorrowedContext(1,(void*)AdvanceAnimatedSpriteFrameAndAttributes,0,120);
}

#pragma force_active reset
