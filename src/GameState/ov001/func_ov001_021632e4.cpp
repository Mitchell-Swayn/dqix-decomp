#include <globaldefs.h>
ARM
extern "C" void *ReadGlobalValueAt02108844();
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" unsigned int ReadNonnegativeIndexedBit(void *, unsigned char *, int);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x021632E4; symbol: func_ov001_021632e4; size: 0x50.
extern "C" int func_ov001_021632e4(void *parameter) {
    void *global = ReadGlobalValueAt02108844();
    int index = ReadScriptParameterAsInteger(parameter);
    unsigned int value = ReadNonnegativeIndexedBit(global, (unsigned char *)global + 0x8c, index);
    if (value) SetNestedSecondWordForTypeThree((char *)parameter + 8, 1);
    else SetNestedSecondWordForTypeThree((char *)parameter + 8, 0);
    return 1;
}
