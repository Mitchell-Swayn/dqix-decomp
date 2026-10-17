#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int GameState_CopySixtyByteFieldAtOffset7504(void *);
// Original: arm9/ov023 @ 0x021ED6CC; symbol: func_ov023_021ed6cc; size: 0x58.
extern "C" bool TestCopiedFlagFieldBit(int bit) {
    unsigned flags[15];
    GameState_CopySixtyByteFieldAtOffset7504(flags);
    int result = 0;
    if (flags[bit / 32] & (1u << (bit % 32))) result = 1;
    if (result != 0) return 1;
    return 0;
}
