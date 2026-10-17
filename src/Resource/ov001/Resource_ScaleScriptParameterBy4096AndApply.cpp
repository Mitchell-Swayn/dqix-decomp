#include <globaldefs.h>
ARM
struct FloatParameterView;
extern "C" ARM unsigned int ReadScriptParameterAsFloat(FloatParameterView *parameter);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
extern unsigned char data_ov001_02165880[];
extern "C" void Util_SetFieldsIfObjectPresent(void *, int);
// Original: arm9/ov001 @ 0x0215D5D0; symbol: func_ov001_0215d5d0; size: 0x38.
extern "C" int Resource_ScaleScriptParameterBy4096AndApply(FloatParameterView *parameter) {
    int scaled = _ffix(_fmul(0x45800000, ReadScriptParameterAsFloat(parameter)));
    void *object = *(void **)(data_ov001_02165880 + 0x24);
    Util_SetFieldsIfObjectPresent(object, scaled);
    return 1;
}
