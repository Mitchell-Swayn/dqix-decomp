#include <globaldefs.h>
ARM

// Original: arm9/ov004 @ 0x02163478; symbol: func_ov004_02163478; size: 0x40.
extern "C" void CycleStateByte(unsigned char *state) {
    state += 0x1000;
    state[0x8fb] = state[0x8fa];
    if (state[0x8fa] == 0) state[0x8fa] = 1;
    else if (state[0x8fa] == 1) state[0x8fa] = 2;
    else if (state[0x8fa] == 2) state[0x8fa] = 0;
}
