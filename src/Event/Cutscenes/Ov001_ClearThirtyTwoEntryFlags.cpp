#include <globaldefs.h>
ARM
extern "C" void *ActorPool_GetGlobalInstance(void);
extern "C" unsigned int *ActorPool_GetActiveSlot(unsigned int **, unsigned int);
// Original: arm9/ov001 @ 0x02161880; symbol: func_ov001_02161880; size: 0x50.
extern "C" int Ov001_ClearThirtyTwoEntryFlags(void) {
    unsigned int *container = (unsigned int *)ActorPool_GetGlobalInstance();
    container[0x98 / 4] &= ~2u;
    int i;
    for (i = 0; i < 0x20; i++) {
        unsigned int *slot = ActorPool_GetActiveSlot((unsigned int **)container, i);
        if (slot != 0) *slot &= ~0x10000u;
    }
    return 1;
}
