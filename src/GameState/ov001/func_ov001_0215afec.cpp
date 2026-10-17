#include <globaldefs.h>
ARM
extern "C" void *_Z11GetBTRandomv();
extern "C" int _Z17NextRandomBetweenP6Randomii(void *, int, int);
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov001 @ 0x0215AFEC; symbol: func_ov001_0215afec; size: 0x54.
extern "C" int func_ov001_0215afec(void *parameter, int count) {
    if (count < 2) return 0;
    void *random = _Z11GetBTRandomv();
    int minimum = ReadScriptParameterAsInteger(parameter);
    int maximum = ReadScriptParameterAsInteger((char *)parameter + 8);
    int value = _Z17NextRandomBetweenP6Randomii(random, minimum, maximum);
    SetNestedSecondWordForTypeThree((char *)parameter + 0x10, value);
    return 1;
}
