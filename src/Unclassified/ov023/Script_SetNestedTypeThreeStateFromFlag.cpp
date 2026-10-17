#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" void SetNestedSecondWordForTypeThree(void *object, int value);
// Original: arm9/ov023 @ 0x021E9278; symbol: func_ov023_021e9278; size: 0x78.
extern "C" int Script_SetNestedTypeThreeStateFromFlag(void *parameter) {
    unsigned char state[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    void *nested = (char *)parameter + 8;
    int enabled = 0;
    int index = ReadScriptParameterAsInteger(parameter);
    unsigned *flags = (unsigned *)(state + 0x4c);
    int bit = index % 32;
    int word = index / 32;
    unsigned mask = 1u << bit;
    unsigned wordValue = flags[word];
    if (wordValue & mask) enabled = 1;
    if (enabled) SetNestedSecondWordForTypeThree(nested, 1);
    else SetNestedSecondWordForTypeThree(nested, 0);
    return 1;
}
