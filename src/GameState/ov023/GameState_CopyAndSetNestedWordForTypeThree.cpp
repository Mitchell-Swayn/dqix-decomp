#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *object, int value);
// Original: arm9/ov023 @ 0x021EA1B0; symbol: func_ov023_021ea1b0; size: 0x30.
extern "C" int GameState_CopyAndSetNestedWordForTypeThree(void *object) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    SetNestedSecondWordForTypeThree(object, *(unsigned *)(buffer + 0x78) >> 16);
    return 1;
}
