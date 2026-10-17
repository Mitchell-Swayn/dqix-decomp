#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EAD74; symbol: func_ov023_021ead74; size: 0x34.
extern "C" bool func_ov023_021ead74(void *arg) {
    unsigned char state[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    SetNestedSecondWordForTypeThree(arg, (*(unsigned int *)(state + 0xa4) << 10) >> 18);
    return true;
}
