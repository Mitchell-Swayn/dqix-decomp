#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void*);
extern "C" unsigned int ComputePercentOf448WithNonzeroMinimumOne(unsigned int*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov023 @ 0x021E99DC; symbol: func_ov023_021e99dc; size: 0x34.
extern "C" bool Grotto_CopyStateAndSetPercent(void* p) {
    unsigned char out[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(out);
    SetNestedSecondWordForTypeThree(p, (int)ComputePercentOf448WithNonzeroMinimumOne((unsigned int*)out));
    return true;
}
