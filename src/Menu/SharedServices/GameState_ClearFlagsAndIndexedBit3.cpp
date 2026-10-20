#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_TestTransitionRequestFlags(void*, unsigned);
extern "C" void GameState_ClearTransitionFlagsPreservingBitFour(unsigned char*);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" void BitArray_SetIndexedBoolean(void*, unsigned char*, int, int);
// Original: arm9/ov004 @ 0x02168884; symbol: func_ov004_02168884; size: 0x38.
extern "C" int GameState_ClearFlagsAndIndexedBit3(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    GameState_TestTransitionRequestFlags(state, 1);
    GameState_ClearTransitionFlagsPreservingBitFour((unsigned char*)state);
    void* base = GameState_GetSerializedProgressState();
    unsigned char* bits = (unsigned char*)base + 0x8c;
    BitArray_SetIndexedBoolean(base, bits, 3, 0);
    return 0;
}
