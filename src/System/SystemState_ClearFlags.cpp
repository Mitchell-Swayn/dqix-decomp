#include <globaldefs.h>
// func_020466f4: 0x020466f4–0x02046708, arm; 20 bytes
// Original: arm9/main @ 0x020466F4; symbol: func_020466f4; size: 0x14.
extern "C" void SystemState_ClearFlags(unsigned int* word, unsigned int mask) {
    *word &= ~mask;
}
