#include <globaldefs.h>
ARM

extern "C" unsigned char *Combat_FindIndexedMonsterObject(void *, int);

// Original: arm9/ov024 @ 0x021F5558; symbol: func_ov024_021f5558; size: 0x44.
extern "C" int GameState_StoreIndexIfObjectFlagClear(void **state, int index, void *unused, int *enabled, short *selected) {
    unsigned char *object = Combat_FindIndexedMonsterObject(*state, index);
    if (object == 0) return 0;
    unsigned char *flags = *(unsigned char **)(object + 0x138);
    if (flags[0x39] != 0) return 0;
    *enabled = 1;
    *selected = index;
    return 1;
}
