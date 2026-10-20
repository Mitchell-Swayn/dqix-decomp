#include <globaldefs.h>
ARM
extern "C" float Script_ReadParameterAsFloat(void *);
extern "C" double _f2d(float);
extern "C" double RuntimeCosine_EvaluateCosine(double);
extern "C" unsigned int _d2f(double);
extern "C" void Script_WriteFloatReferenceOutput(unsigned int *, unsigned int);
// Original: arm9/ov001 @ 0x0215AF60; symbol: func_ov001_0215af60; size: 0x2C.
extern "C" int SetObjectCosineOfScriptFloat(void *object) {
    float input = Script_ReadParameterAsFloat(object);
    unsigned int result = _d2f(RuntimeCosine_EvaluateCosine(_f2d(input)));
    Script_WriteFloatReferenceOutput((unsigned int *)((char *)object + 8), result);
    return 1;
}
