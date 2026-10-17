#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_TestByteFlagsAtOffset63DC(void*, unsigned);
extern "C" void GameState_ClearByteFlagsExceptBitFourAtOffset63DC(unsigned char*);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" void BitArray_SetIndexedBoolean(void*, unsigned char*, int, int);
// Original: arm9/ov004 @ 0x02168884; symbol: func_ov004_02168884; size: 0x38.
extern "C" int GameState_ClearFlagsAndIndexedBit3(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    GameState_TestByteFlagsAtOffset63DC(state, 1);
    GameState_ClearByteFlagsExceptBitFourAtOffset63DC((unsigned char*)state);
    void* base = ReadGlobalValueAt02108844();
    unsigned char* bits = (unsigned char*)base + 0x8c;
    BitArray_SetIndexedBoolean(base, bits, 3, 0);
    return 0;
}
