#include <globaldefs.h>
ARM
#pragma optimization_level 4

extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

// Original: arm9/ov023 @ 0x021EADA8; symbol: func_ov023_021eada8; size: 0x34.
extern "C" int func_ov023_021eada8(void *arg) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    int value = *(int *)(buffer + 0xa8);
    value = (unsigned int)value << 8;
    value = (unsigned int)value >> 8;
    SetNestedSecondWordForTypeThree(arg, value);
    return 1;
}
