#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalValueAt02108844();
extern "C" unsigned ReadNonnegativeIndexedBit(void*, unsigned char*, int);
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov001 @ 0x02163390; symbol: func_ov001_02163390; size: 0x5C.
extern "C" int Grotto_SetNestedIndexedBitResult(void* parameter) {
    char* global = (char*)ReadGlobalValueAt02108844();
    int index = ReadScriptParameterAsInteger(parameter);
    unsigned char count = *(unsigned char*)(global + 0x332);
    unsigned char* bits = (unsigned char*)global + count * 0x1c + 0x10;
    unsigned value = ReadNonnegativeIndexedBit(global, bits, index);
    if (value != 0)
        SetNestedSecondWordForTypeThree((char*)parameter + 8, 1);
    else
        SetNestedSecondWordForTypeThree((char*)parameter + 8, 0);
    return 1;
}
