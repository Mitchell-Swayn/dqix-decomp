#include <globaldefs.h>
ARM
extern "C" float ReadScriptParameterAsFloat(void *);
extern "C" double _f2d(float);
extern "C" double Runtime_ComputeSine(double);
extern "C" unsigned int _d2f(double);
extern "C" void SetKindThreeIndirectWord4(unsigned int *, unsigned int);
// Original: arm9/ov001 @ 0x0215AF34; symbol: func_ov001_0215af34; size: 0x2C.
extern "C" int Script_SetSineOfParameterAsKindThreeWord(void *parameter) {
    double angle = _f2d(ReadScriptParameterAsFloat(parameter));
    unsigned int result = _d2f(Runtime_ComputeSine(angle));
    SetKindThreeIndirectWord4((unsigned int *)((unsigned char *)parameter + 8), result);
    return 1;
}
