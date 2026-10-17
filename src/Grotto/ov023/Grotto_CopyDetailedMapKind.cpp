#include <globaldefs.h>
ARM
#pragma optimization_level 1
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E9CF8; symbol: func_ov023_021e9cf8; size: 0x34.
extern "C" int Grotto_CopyDetailedMapKind(void *out) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int value = *(volatile unsigned int *)(buffer + 0x30);
    SetNestedSecondWordForTypeThree(out, (unsigned int)((int)value << 8) >> 8);
    return 1;
}
