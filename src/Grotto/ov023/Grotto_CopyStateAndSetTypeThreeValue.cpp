#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov023 @ 0x021E98DC; symbol: func_ov023_021e98dc; size: 0x34.
extern "C" bool Grotto_CopyStateAndSetTypeThreeValue(void* p) {
    unsigned char out[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(out);
    SetNestedSecondWordForTypeThree(p, (*(unsigned int*)(out + 0x10) << 9) >> 18);
    return true;
}
