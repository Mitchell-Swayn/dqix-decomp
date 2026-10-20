#include <globaldefs.h>
ARM
extern "C" void* GameState_GetSerializedProgressState();
extern "C" unsigned BitArray_ReadNonnegativeIndexMask(void*, unsigned char*, int);
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov001 @ 0x02163390; symbol: func_ov001_02163390; size: 0x5C.
extern "C" int Grotto_SetNestedIndexedBitResult(void* parameter) {
    char* global = (char*)GameState_GetSerializedProgressState();
    int index = Script_ReadParameterAsInteger(parameter);
    unsigned char count = *(unsigned char*)(global + 0x332);
    unsigned char* bits = (unsigned char*)global + count * 0x1c + 0x10;
    unsigned value = BitArray_ReadNonnegativeIndexMask(global, bits, index);
    if (value != 0)
        Script_WriteIntegerReferenceOutput((char*)parameter + 8, 1);
    else
        Script_WriteIntegerReferenceOutput((char*)parameter + 8, 0);
    return 1;
}
