#include <globaldefs.h>
ARM

extern "C" void *FindIndexedGameStateObjectWithFlag400(void *state, int index);

// Original: arm9/ov024 @ 0x021F5C80; symbol: func_ov024_021f5c80; size: 0x64.
extern "C" int GameState_StoreValueUnlessThreeFlagGroupsPassThreshold(void **state, int index, void *unused, int *changed, short *stored) {
    void *object = FindIndexedGameStateObjectWithFlag400(*state, index);
    if (object == 0) return 0;
    unsigned int flags = *(unsigned int *)(*(unsigned char **)((char *)object + 0x138) + 0x58);
    if (((int)(flags << 29) >> 29) >= 2 && ((int)(flags << 26) >> 29) >= 2 && ((int)(flags << 23) >> 29) >= 2) return 0;
    *changed = 1;
    *stored = index;
    return 1;
}
