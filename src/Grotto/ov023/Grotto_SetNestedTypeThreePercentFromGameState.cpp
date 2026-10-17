#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" ARM unsigned ComputePercentOf307WithNonzeroMinimumOne(void *p);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E99A8; symbol: func_ov023_021e99a8; size: 0x34.
extern "C" int Grotto_SetNestedTypeThreePercentFromGameState(void *p) {
    unsigned char output[0xB0];
    GameState_CopyB0ByteStateBufferToOutput(output);
    unsigned value = ComputePercentOf307WithNonzeroMinimumOne(output);
    SetNestedSecondWordForTypeThree(p, value);
    return 1;
}
