#include <globaldefs.h>
ARM

extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

// Original: arm9/ov023 @ 0x021EAB64; symbol: func_ov023_021eab64; size: 0x3C.
extern "C" bool func_ov023_021eab64(void *out) {
    unsigned char state[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    volatile unsigned char *field = state + 0x94;
    SetNestedSecondWordForTypeThree(out, *(unsigned short *)field);
    SetNestedSecondWordForTypeThree((unsigned char *)out + 8, field[2]);
    return true;
}
