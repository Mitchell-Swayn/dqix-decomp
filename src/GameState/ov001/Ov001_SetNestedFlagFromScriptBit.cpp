#include <globaldefs.h>
extern "C" void *ReadGlobalValueAt02108844(void);
extern "C" unsigned int ReadNonnegativeIndexedBit(void *, unsigned char *, int);
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x02163334; symbol: func_ov001_02163334; size: 0x5C.
extern "C" int Ov001_SetNestedFlagFromScriptBit(void *parameter) {
    void *global = ReadGlobalValueAt02108844();
    int bit = ReadScriptParameterAsInteger(parameter);
    unsigned char count = *(unsigned char *)((char *)global + 0x332);
    unsigned char *bits = (unsigned char *)global + count * 0x1c + 3;
    int value = ReadNonnegativeIndexedBit(global, bits, bit);
    if (value != 0) {
        SetNestedSecondWordForTypeThree((char *)parameter + 8, 1);
    } else {
        SetNestedSecondWordForTypeThree((char *)parameter + 8, 0);
    }
    return 1;
}
