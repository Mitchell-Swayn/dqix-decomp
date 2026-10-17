#include <globaldefs.h>
ARM
extern unsigned char data_ov031_0224e5c4[];
extern "C" void *SelectStateWordByPriorityMask(unsigned);
typedef void (*StateHandler)(unsigned, int, int);
// Original: arm9/ov031 @ 0x02213270; symbol: func_ov031_02213270; size: 0x64.
extern "C" void GameState_ClearMaskBitAndInvokeHandler(unsigned mask, int arg1, int arg2) {
    unsigned char *state = (unsigned char *)SelectStateWordByPriorityMask(1);
    if (state == 0) return;
    unsigned char flags = state[8];
    if ((flags & mask) == 0) return;
    state[8] = (unsigned char)(flags & ~mask);
    StateHandler handler = *(StateHandler *)(state + 4);
    handler(mask, arg1, arg2);
    if (mask == 1) *(unsigned int *)(data_ov031_0224e5c4 + 0xC) = 0;
}
