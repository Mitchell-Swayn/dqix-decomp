#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetIndexList(void *);
extern "C" int MiniMedalMenu_GetPlacementState(void *, int);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void _ZN13ZoneState2754C1Ev(void *);
extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char *);
extern "C" void PlacementAllocator_ApplyCountByRecordKindAndAvailableActors(void *, int, int, int);
// Original: arm9/ov004 @ 0x02167A6C; symbol: func_ov004_02167a6c; size: 0x70.
extern "C" int MiniMedalMenu_AwardItemThroughPlacementState(void *object, int count) {
    (void)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    int allocation = MiniMedalMenu_GetPlacementState(object, 5);
    if (allocation) {
        unsigned char local[0x38];
        _ZN13SafeAllocator21ResetAllocatorPointerEv(local);
        _ZN13ZoneState2754C1Ev(local + 0x14);
        World_ResetZoneStateAndClearThreeWords(local);
        World_ResetZoneStateAndClearThreeWords(local);
        *(int *)(local + 0x2c) = allocation;
        PlacementAllocator_ApplyCountByRecordKindAndAvailableActors(local, count, 1, 0);
    }
    return 0;
}
