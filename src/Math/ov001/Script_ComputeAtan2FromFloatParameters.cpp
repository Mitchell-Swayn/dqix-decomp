#include <globaldefs.h>
ARM
extern "C" float ReadScriptParameterAsFloat(void *);
extern "C" double RuntimeMathEntries_ComputeAtan2(double, double);
extern "C" void SetKindThreeIndirectWord4(unsigned int *, float);
// Original: arm9/ov001 @ 0x0215AF8C; symbol: func_ov001_0215af8c; size: 0x60.
extern "C" bool Script_ComputeAtan2FromFloatParameters(void *parameters) {
    float y = ReadScriptParameterAsFloat(parameters);
    float x = ReadScriptParameterAsFloat((unsigned char *)parameters + 8);
    double angle = RuntimeMathEntries_ComputeAtan2((double)y, (double)x);
    float result = (float)angle;
    SetKindThreeIndirectWord4((unsigned int *)((unsigned char *)parameters + 0x10), result);
    return true;
}
