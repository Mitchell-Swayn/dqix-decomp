#include <globaldefs.h>
ARM
extern "C" float Script_ReadParameterAsFloat(void *);
extern "C" double _f2d(float);
extern "C" double Runtime_ComputeSine(double);
extern "C" unsigned int _d2f(double);
extern "C" void Script_WriteFloatReferenceOutput(unsigned int *, unsigned int);
// Original: arm9/ov001 @ 0x0215AF34; symbol: func_ov001_0215af34; size: 0x2C.
extern "C" int Script_SetSineOfParameterAsKindThreeWord(void *parameter) {
    double angle = _f2d(Script_ReadParameterAsFloat(parameter));
    unsigned int result = _d2f(Runtime_ComputeSine(angle));
    Script_WriteFloatReferenceOutput((unsigned int *)((unsigned char *)parameter + 8), result);
    return 1;
}
