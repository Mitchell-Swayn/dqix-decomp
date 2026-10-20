#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
// Original: arm9/ov003 @ 0x0215B580; symbol: func_ov003_0215b580; size: 0x44.
extern "C" int TryAddAmountWith9999999Cap(void *unused, int amount) {
    int *list = (int *)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    int current = *(int *)((unsigned char *)list + 0xf6c);
    if (current < -amount) return 0;
    current += amount;
    *(int *)((unsigned char *)list + 0xf6c) = current;
    if ((unsigned)current > 9999999u) *(int *)((unsigned char *)list + 0xf6c) = 9999999;
    return 1;
}
