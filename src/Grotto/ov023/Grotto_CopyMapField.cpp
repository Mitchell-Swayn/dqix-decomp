#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA214; symbol: func_ov023_021ea214; size: 0x34.
extern "C" int Grotto_CopyMapField(void *out) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int value = *(unsigned int *)(buffer + 0x7c);
    SetNestedSecondWordForTypeThree(out, (value << 12) >> 22);
    return 1;
}
