#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void __clear(void*, unsigned);
extern "C" int GameState_CopyByteBufferAtOffset5718(void*, void*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov023 @ 0x021EA3AC; symbol: func_ov023_021ea3ac; size: 0x40.
extern "C" int Grotto_InitializeNestedValueFromGameState(void* destination) {
    void* state = _ZN9GameState11GetInstanceEv();
    unsigned value;
    __clear(&value, 4);
    int result = GameState_CopyByteBufferAtOffset5718(state, &value);
    SetNestedSecondWordForTypeThree(destination, result - 1);
    return 1;
}
