#include <globaldefs.h>
ARM
extern "C" void *GameState_GetIndexList(void *);
// Original: arm9/ov017 @ 0x021D0D9C; symbol: func_ov017_021d0d9c; size: 0x20.
extern "C" void func_ov017_021d0d9c(void *unused, void *source, void *state) {
    unsigned int *list = (unsigned int *)((unsigned char *)GameState_GetIndexList(state) + 0x2c94);
    *list = *(unsigned int *)((unsigned char *)source + 4);
}
