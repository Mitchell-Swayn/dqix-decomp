#include <globaldefs.h>
#pragma optimize_for_size off

// Layout projections and call contracts from the matched sprite position and task owners.
struct PackedEntry { unsigned int value; unsigned int other; };
struct EntryOwner { unsigned int preceding[2]; PackedEntry* entries; };
struct Pair { unsigned short x, y; };
extern "C" void WfcUtility_GetSpriteGroupPosition(EntryOwner*, int, unsigned int*, unsigned int*);
extern "C" void WfcUtility_SetSpriteGroupPosition(void*, int, unsigned, unsigned);
extern "C" void WfcUtility_SetTaskCallback(void*,void (*)(void*,void*));
// Original data: arm9/ov031 @ 0x02290D04; symbol: data_ov031_02290d04; shared mode-sprite context.
extern "C" char* AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x0224926A; symbol: data_ov031_0224926a; original sprite-coordinate pairs.
extern "C" Pair WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant3[];
#define GROUPS ((void**)AdvancePackedHighFieldToward152_UnknownRoleZeroInitializedStorage[1])
#define POSITIONS WfcUtilityCreateAnimatedHeaderSprites_UnknownRoleInitializedBytes_Variant3
struct Node { unsigned a, b; unsigned* records; unsigned char count; };
extern "C" void Network_UnlinkNodeAndReleaseRecords(Node*);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void**);
extern "C" void WfcUtility_RequestTaskRemoval(unsigned,void*);
// Original data: arm9/ov031 @ 0x02290D08; symbol: data_ov031_02290d08; shared mode-sprite allocation slot.
extern "C" void* WfcUtilitySlideModeSpritesOffscreenAndRelease_UnknownRoleZeroInitializedStorage;
#pragma force_active on
// Original: arm9/ov031 @ 0x022372B0; symbol: func_ov031_022372b0; size: 0xD8.
// Moves all mode sprites offscreen, then removes the animation task and releases its sprite groups and allocation.
extern "C" void WfcUtility_SlideModeSpritesOffscreenAndRelease(void* self,void*)
{
    unsigned int x, y;
    WfcUtility_GetSpriteGroupPosition((EntryOwner*)GROUPS[0], 0, &x, &y);
    x -= 8;
    int i = 0;
    do
    {
        WfcUtility_SetSpriteGroupPosition(GROUPS[i], -1, x, ((Pair*)((unsigned char*)POSITIONS + i * 4))->y);
    } while (++i < 5);
    if ((int)x > 470)
        return;
    if ((int)x < 256)
        return;
    WfcUtility_RequestTaskRemoval(0, self);
    int group = 0;
    do
    {
        Network_UnlinkNodeAndReleaseRecords((Node*)GROUPS[group]);
    } while (++group < 5);
    WfcUtility_FreeAllocationAndClearPointer(&WfcUtilitySlideModeSpritesOffscreenAndRelease_UnknownRoleZeroInitializedStorage);
}
