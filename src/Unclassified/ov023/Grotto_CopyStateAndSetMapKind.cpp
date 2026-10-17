#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA248; symbol: func_ov023_021ea248; size: 0x30.
extern "C" unsigned int Grotto_CopyStateAndSetMapKind(void *object) {
    unsigned char state[0xB0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    SetNestedSecondWordForTypeThree(object, *(unsigned int *)(state + 0x7C) >> 20);
    return 1;
}
