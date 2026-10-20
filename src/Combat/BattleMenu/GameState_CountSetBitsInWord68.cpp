#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0218155C; symbol: func_ov000_0218155c; size: 0x30.
extern "C" unsigned int GameState_CountSetBitsInWord68(void *object) {
    unsigned int count = 0;
    for (unsigned int bit = 0; bit < 12; ++bit) {
        if (*(unsigned int *)((char *)object + 0x68) & (1u << bit))
            ++count;
    }
    return count;
}
