#include <globaldefs.h>
ARM
struct Random;
extern "C" unsigned _Z16GetRandomStateHiP6Random(Random*);
extern "C" unsigned _Z16GetRandomStateLoP6Random(Random*);
// Original: arm9/ov000 @ 0x021605D0; symbol: func_ov000_021605d0; size: 0x50.
extern "C" void GameState_CopyStateAndResetRandomStreams(unsigned char* destination, const unsigned* source) {
    *(unsigned*)(destination + 0x29c) = source[0];
    *(unsigned*)(destination + 0x2a0) = source[1];
    *(unsigned*)(destination + 4) = source[2];
    Random* random = *(Random**)(destination + 0x29c);
    if (!random) return;
    *(unsigned*)(destination + 0x6e3c) = _Z16GetRandomStateHiP6Random(random);
    *(unsigned*)(destination + 0x6e40) = _Z16GetRandomStateLoP6Random(random);
}
