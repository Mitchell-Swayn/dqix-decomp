#include <globaldefs.h>
ARM
#pragma optimization_level 4

extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

struct StateWord { unsigned int value : 10; };

// Original: arm9/ov023 @ 0x021EA2DC; symbol: func_ov023_021ea2dc; size: 0x34.
extern "C" int CopyTypeThreeSecondWordFromGameState(void *arg) {
    unsigned char state[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    SetNestedSecondWordForTypeThree(arg, ((StateWord *)(state + 0x84))->value);
    return 1;
}
