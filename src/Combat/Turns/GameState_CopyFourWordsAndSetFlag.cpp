#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02163378; symbol: func_ov000_02163378; size: 0x40.
extern "C" void GameState_CopyFourWordsAndSetFlag(unsigned char *destination, const unsigned int *source, unsigned char value) {
    for (int i = 0; i < 4; ++i) {
        *(unsigned int *)(destination + 0x5000 + i * 4 + 0x758) = source[i];
    }
    destination[0x5000 + 0x76C] = value;
    *(unsigned int *)(destination + 0x5000 + 0x5F4) |= 0x4000;
}
