#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA1E0; symbol: func_ov023_021ea1e0; size: 0x34.
extern "C" int Grotto_CopyDetailedMapLevel(void *out) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int value = *(unsigned int *)(buffer + 0x7c);
    SetNestedSecondWordForTypeThree(out, (unsigned int)(unsigned short)(value << 6) >> 6);
    return 1;
}
