#include <globaldefs.h>
// func_020466e4: 0x020466e4–0x020466f4, arm; 16 bytes
// Original: arm9/main @ 0x020466E4; symbol: func_020466e4; size: 0x10.
extern "C" void SetWordMaskBits_Main020466E4(unsigned int* word, unsigned int mask) {
    *word |= mask;
}
