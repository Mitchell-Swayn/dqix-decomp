#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void* out);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov023 @ 0x021E9E98; symbol: func_ov023_021e9e98; size: 0x34.
extern "C" int Grotto_SetTypeThreeSecondWordFromStateWord40(void* output) {
    char buffer[0xB0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int value = (*(volatile unsigned int*)(buffer + 0x40) << 8) >> 8;
    SetNestedSecondWordForTypeThree(output, value);
    return 1;
}
