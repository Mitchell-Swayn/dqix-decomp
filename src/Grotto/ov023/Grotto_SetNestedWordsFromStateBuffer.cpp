#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021EAB28; symbol: func_ov023_021eab28; size: 0x3C.
extern "C" int Grotto_SetNestedWordsFromStateBuffer(void *arg) {
    unsigned char state[0xB0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    unsigned short *value = (unsigned short *)(state + 0x90);
    SetNestedSecondWordForTypeThree(arg, *value);
    SetNestedSecondWordForTypeThree((char *)arg + 8, *((unsigned char *)value + 2));
    return 1;
}
