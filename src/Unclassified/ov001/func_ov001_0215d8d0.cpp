#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void InitializeReturnedObjectWith15AndInputAt1C(void *, int);
extern "C" unsigned int data_ov001_02165880[];
// Original: arm9/ov001 @ 0x0215D8D0; symbol: func_ov001_0215d8d0; size: 0x24.
extern "C" int func_ov001_0215d8d0(void *parameter) {
    int value = ReadScriptParameterAsInteger(parameter);
    InitializeReturnedObjectWith15AndInputAt1C((void *)data_ov001_02165880[9], value);
    return 1;
}
