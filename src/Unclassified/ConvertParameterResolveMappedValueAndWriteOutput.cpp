#include <globaldefs.h>
extern "C" int ReadGlobalValueAt02108844(void); extern "C" unsigned int ReadScriptParameterAsInteger(int);
extern "C" unsigned int Object_ReadFlagWithHighIdentifierRemapping(int, unsigned int); extern "C" void SetNestedSecondWordForTypeThree(int, unsigned int);
ARM
// Original: arm9/main @ 0x0209D4D0; symbol: func_0209d4d0; size: 0x40.
extern "C" int ConvertParameterResolveMappedValueAndWriteOutput(int p) {
    int context=ReadGlobalValueAt02108844(); if (!context) return 0;
    unsigned int item=ReadScriptParameterAsInteger(p); item=Object_ReadFlagWithHighIdentifierRemapping(context,item);
    SetNestedSecondWordForTypeThree(p+8,item); return 1;
}
