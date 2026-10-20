#include <globaldefs.h>
ARM
extern "C" void *GameState_GetSerializedProgressState();
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" int Script_GetRemappedProgressFlagMask(char *, int);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x021633EC; symbol: func_ov001_021633ec; size: 0x4C.
extern "C" int Script_TestRemappedProgressFlag(void *parameter) {
    int value = Script_GetRemappedProgressFlagMask((char *)GameState_GetSerializedProgressState(), Script_ReadParameterAsInteger(parameter));
    if (value) Script_WriteIntegerReferenceOutput((char *)parameter + 8, 1);
    else Script_WriteIntegerReferenceOutput((char *)parameter + 8, 0);
    return 1;
}
