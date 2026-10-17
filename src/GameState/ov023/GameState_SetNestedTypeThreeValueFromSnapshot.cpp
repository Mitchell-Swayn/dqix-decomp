#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E9910; symbol: func_ov023_021e9910; size: 0x34.
extern "C" int GameState_SetNestedTypeThreeValueFromSnapshot(void* object) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned int field = *(unsigned int*)(buffer + 0xc);
    SetNestedSecondWordForTypeThree(object, (int)((field << 4) >> 18));
    return 1;
}
