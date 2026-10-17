#include <globaldefs.h>
THUMB
extern "C" void System_Copy8WithReversedPointers(void *, const void *, unsigned int);
extern "C" unsigned int func_ov031_0221e650(const char *);
extern "C" char data_ov031_0224b0d0[];
extern "C" char data_ov031_0224b0dc[];
// Original: arm9/ov031 @ 0x0221D310; symbol: func_ov031_0221d310; size: 0x44.
extern "C" int Overlay_CopyTwoStringsAndCheckLength(unsigned *state) {
    state[0] = func_ov031_0221e650(data_ov031_0224b0d0);
    System_Copy8WithReversedPointers(state + 1, data_ov031_0224b0d0, state[0]);
    state[9] = 1;
    state[10] = func_ov031_0221e650(data_ov031_0224b0dc);
    if (state[10] > 13) return -1;
    System_Copy8WithReversedPointers(state + 11, data_ov031_0224b0dc, state[10]);
    return 0;
}
