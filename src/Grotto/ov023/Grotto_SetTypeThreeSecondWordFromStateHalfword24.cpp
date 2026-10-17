#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void* out);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov023 @ 0x021E9F30; symbol: func_ov023_021e9f30; size: 0x34.
extern "C" int Grotto_SetTypeThreeSecondWordFromStateHalfword24(void* output) {
    char buffer[0xB0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int value = (*(volatile unsigned int*)(buffer + 0x24) << 16) >> 16;
    SetNestedSecondWordForTypeThree(output, value);
    return 1;
}
