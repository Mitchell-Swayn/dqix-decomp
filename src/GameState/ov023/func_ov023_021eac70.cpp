#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EAC70; symbol: func_ov023_021eac70; size: 0x34.
extern "C" int func_ov023_021eac70(void *out) {
    unsigned char state[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    SetNestedSecondWordForTypeThree(out, ((*(unsigned int *)(state + 0x9c)) << 8) >> 25);
    return 1;
}
