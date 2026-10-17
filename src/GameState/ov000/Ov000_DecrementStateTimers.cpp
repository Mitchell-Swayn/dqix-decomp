#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021824D8; symbol: func_ov000_021824d8; size: 0x44.
extern "C" void Ov000_DecrementStateTimers(char *state) {
    if (*(short *)(state + 0x6ea) > 0) --*(short *)(state + 0x6ea);
    if (*(short *)(state + 0x6ec) <= 0) return;
    --*(short *)(state + 0x6ec);
    if (*(short *)(state + 0x6ec) == 0) {
        state[0x6e8] = 0;
        state[0x6e9] = 0;
    }
}
