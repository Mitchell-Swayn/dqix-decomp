#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" void Script_WriteIntegerReferenceOutput(void *object, int value);
// Original: arm9/ov023 @ 0x021E9278; symbol: func_ov023_021e9278; size: 0x78.
extern "C" int Script_ReadStatisticsFlag(void *parameter) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    void *nested = (char *)parameter + 8;
    int enabled = 0;
    int index = Script_ReadParameterAsInteger(parameter);
    unsigned *flags = (unsigned *)(state + 0x4c);
    int bit = index % 32;
    int word = index / 32;
    unsigned mask = 1u << bit;
    unsigned wordValue = flags[word];
    if (wordValue & mask) enabled = 1;
    if (enabled) Script_WriteIntegerReferenceOutput(nested, 1);
    else Script_WriteIntegerReferenceOutput(nested, 0);
    return 1;
}
