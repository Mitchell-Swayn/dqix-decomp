#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void UpdateByteLevelTransitionAndThreeChannels(unsigned char *, int, int);
extern "C" unsigned char data_02109bf4;
// Original: arm9/ov001 @ 0x021636D0; symbol: func_ov001_021636d0; size: 0x54.
extern "C" bool Script_UpdateByteLevelWithOptionalDuration(void *parameters, int count) {
    int value = ReadScriptParameterAsInteger(parameters);
    if (value < 0) value = 0;
    else if (value > 0x7F) value = 0x7F;
    int duration = 0;
    if (count >= 2) duration = ReadScriptParameterAsInteger((unsigned char *)parameters + 8);
    UpdateByteLevelTransitionAndThreeChannels(&data_02109bf4, value, duration);
    return true;
}
