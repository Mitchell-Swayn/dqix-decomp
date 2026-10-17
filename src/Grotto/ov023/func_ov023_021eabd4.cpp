#include <globaldefs.h>
ARM

extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

// Original: arm9/ov023 @ 0x021EABD4; symbol: func_ov023_021eabd4; size: 0x34.
extern "C" int func_ov023_021eabd4(void *arg) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int value = *(unsigned int *)(buffer + 0x98);
    value <<= 8;
    value >>= 25;
    SetNestedSecondWordForTypeThree(arg, value);
    return 1;
}
