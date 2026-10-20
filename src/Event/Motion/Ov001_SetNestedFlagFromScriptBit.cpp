#include <globaldefs.h>
extern "C" void *GameState_GetSerializedProgressState(void);
extern "C" unsigned int BitArray_ReadNonnegativeIndexMask(void *, unsigned char *, int);
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x02163334; symbol: func_ov001_02163334; size: 0x5C.
extern "C" int Ov001_SetNestedFlagFromScriptBit(void *parameter) {
    void *global = GameState_GetSerializedProgressState();
    int bit = Script_ReadParameterAsInteger(parameter);
    unsigned char count = *(unsigned char *)((char *)global + 0x332);
    unsigned char *bits = (unsigned char *)global + count * 0x1c + 3;
    int value = BitArray_ReadNonnegativeIndexMask(global, bits, bit);
    if (value != 0) {
        Script_WriteIntegerReferenceOutput((char *)parameter + 8, 1);
    } else {
        Script_WriteIntegerReferenceOutput((char *)parameter + 8, 0);
    }
    return 1;
}
