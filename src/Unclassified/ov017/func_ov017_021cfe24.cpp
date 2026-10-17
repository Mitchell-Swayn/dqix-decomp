#include <globaldefs.h>
ARM
extern "C" void GameState_ApplyBoundedKeyFlagsAndBitArray(unsigned short, unsigned short, unsigned short);
// Original: arm9/ov017 @ 0x021CFE24; symbol: func_ov017_021cfe24; size: 0x1C.
extern "C" void func_ov017_021cfe24(int, void *p) {
    GameState_ApplyBoundedKeyFlagsAndBitArray(*(unsigned short *)((char *)p + 4), *(unsigned short *)((char *)p + 6), *(unsigned short *)((char *)p + 8));
}
