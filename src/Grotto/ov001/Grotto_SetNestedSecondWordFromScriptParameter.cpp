#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *parameter);
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short *p, unsigned int mask);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
extern "C" unsigned short data_02114e30;
// Original: arm9/ov001 @ 0x0215AE84; symbol: func_ov001_0215ae84; size: 0x34.
extern "C" int Grotto_SetNestedSecondWordFromScriptParameter(void *parameter) {
    int value = ReadScriptParameterAsInteger(parameter);
    int result = Object_TestNewlySetHalfwordMask(&data_02114e30, (unsigned short)value);
    SetNestedSecondWordForTypeThree((char *)parameter + 8, result);
    return 1;
}
