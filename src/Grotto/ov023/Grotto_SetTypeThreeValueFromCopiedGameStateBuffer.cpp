#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EA854; symbol: func_ov023_021ea854; size: 0x30.
extern "C" int Grotto_SetTypeThreeValueFromCopiedGameStateBuffer(void *object) {
    char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int value = *(unsigned int *)(buffer + 0x1c) >> 16;
    SetNestedSecondWordForTypeThree(object, value);
    return 1;
}
