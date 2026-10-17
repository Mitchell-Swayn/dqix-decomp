#include <globaldefs.h>
ARM
extern "C" unsigned int ReadScriptParameterAsFloat(void*);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(void);
extern "C" void Ov001_InitializeReturnedObject(void*, int);
extern "C" unsigned int data_ov001_02165880;
// Original: arm9/ov001 @ 0x0215D560; symbol: func_ov001_0215d560; size: 0x38.
extern "C" int func_ov001_0215d560(void* parameter) {
    unsigned int value = _fmul(0x45800000, ReadScriptParameterAsFloat(parameter));
    int integer = _ffix();
    void* object = *(void**)((char*)&data_ov001_02165880 + 0x24);
    Ov001_InitializeReturnedObject(object, integer);
    return 1;
}
