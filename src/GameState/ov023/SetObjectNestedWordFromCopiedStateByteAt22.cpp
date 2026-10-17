#include <globaldefs.h>
ARM
extern "C" int GameState_CopyB0ByteStateBufferToOutput(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA8B8; symbol: func_ov023_021ea8b8; size: 0x30.
extern "C" int SetObjectNestedWordFromCopiedStateByteAt22(void *object) {
    unsigned char state[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    unsigned int word = *(unsigned int *)(state + 0x20);
    SetNestedSecondWordForTypeThree(object, (int)(word >> 16));
    return 1;
}
