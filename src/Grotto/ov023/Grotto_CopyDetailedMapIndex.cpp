#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA17C; symbol: func_ov023_021ea17c; size: 0x34.
extern "C" int Grotto_CopyDetailedMapIndex(void *out) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int value = *(unsigned int *)(buffer + 0x78);
    SetNestedSecondWordForTypeThree(out, (unsigned int)((int)value << 16) >> 16);
    return 1;
}
