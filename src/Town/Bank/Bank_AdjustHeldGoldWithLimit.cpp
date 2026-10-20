#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
// Original: arm9/ov003 @ 0x02169938; symbol: func_ov003_02169938; size: 0x44.
extern "C" int Bank_AdjustHeldGoldWithLimit(void *unused, int amount) {
    void *list = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    int current = *(int *)((char *)list + 0xf6c);
    if (current < -amount) return 0;
    int updated = current + amount;
    *(int *)((char *)list + 0xf6c) = updated;
    if ((unsigned int)updated > 0x98967f) *(int *)((char *)list + 0xf6c) = 0x98967f;
    return 1;
}
