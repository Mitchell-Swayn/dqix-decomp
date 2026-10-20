#include <globaldefs.h>
ARM
extern "C" void *GameState_GetSerializedProgressState();
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" unsigned int BitArray_ReadNonnegativeIndexMask(void *, unsigned char *, int);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x021632E4; symbol: func_ov001_021632e4; size: 0x50.
extern "C" int Script_TestSerializedProgressBit(void *parameter) {
    void *global = GameState_GetSerializedProgressState();
    int index = Script_ReadParameterAsInteger(parameter);
    unsigned int value = BitArray_ReadNonnegativeIndexMask(global, (unsigned char *)global + 0x8c, index);
    if (value) Script_WriteIntegerReferenceOutput((char *)parameter + 8, 1);
    else Script_WriteIntegerReferenceOutput((char *)parameter + 8, 0);
    return 1;
}
