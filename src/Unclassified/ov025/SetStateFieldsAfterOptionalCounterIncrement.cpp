#include <globaldefs.h>
ARM

// Original: arm9/ov025 @ 0x021DEF30; symbol: func_ov025_021def30; size: 0x34.
extern "C" void SetStateFieldsAfterOptionalCounterIncrement(char *state) {
    if (*(unsigned short *)(state + 0x770a) == 0) {
        ++*(unsigned int *)(state + 0x55d8);
    }
    *(unsigned int *)(state + 0xeac) = 1;
    *(unsigned int *)(state + 0x770c) = 0;
}
