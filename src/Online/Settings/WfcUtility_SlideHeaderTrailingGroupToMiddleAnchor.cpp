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
extern "C" void WfcUtility_SlideHeaderInnerGroupToCenterAnchor(void*,void*);
#pragma force_active on
// Original: arm9/ov031 @ 0x02236AEC; symbol: func_ov031_02236aec; size: 0xE4.
// Moves the trailing mode-sprite group by eight pixels, clamps it at its anchor, and installs the next animation phase.
extern "C" void WfcUtility_SlideHeaderTrailingGroupToMiddleAnchor(void* self,void*)
{
    unsigned int x, y;
    WfcUtility_GetSpriteGroupPosition((EntryOwner*)GROUPS[1], 0, &x, &y);
    x += 8;
    if ((int)x < 80 || (int)x > 256)
    {
        int i = 1;
        do
        {
            WfcUtility_SetSpriteGroupPosition(GROUPS[i], -1, x, ((Pair*)((unsigned char*)POSITIONS + i * 4))->y);
        } while (++i < 5);
        return;
    }
    x = 80;
    int i = 1;
    do
    {
        WfcUtility_SetSpriteGroupPosition(GROUPS[i], -1, x, ((Pair*)((unsigned char*)POSITIONS + i * 4))->y);
    } while (++i < 5);
    WfcUtility_SetTaskCallback(self, WfcUtility_SlideHeaderInnerGroupToCenterAnchor);
}
