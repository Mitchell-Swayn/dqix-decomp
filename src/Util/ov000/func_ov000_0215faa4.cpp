#include <globaldefs.h>
#include <Util/Random.h>
ARM
// Original: arm9/ov000 @ 0x0215FAA4; symbol: func_ov000_0215faa4; size: 0xC.
extern "C" void func_ov000_0215faa4(struct Random *random, unsigned int stateHi, unsigned int stateLo) {
    SeedRandom32(random, stateHi, stateLo);
}
