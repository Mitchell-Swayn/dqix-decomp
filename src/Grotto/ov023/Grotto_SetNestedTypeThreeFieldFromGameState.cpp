#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E9BB0; symbol: func_ov023_021e9bb0; size: 0x34.
extern "C" int Grotto_SetNestedTypeThreeFieldFromGameState(void *p) {
    unsigned char output[0xB0];
    GameState_CopyB0ByteStateBufferToOutput(output);
    unsigned value = (*(unsigned int *)(output + 0x18) << 0xC) >> 0x1C;
    SetNestedSecondWordForTypeThree(p, value);
    return 1;
}
