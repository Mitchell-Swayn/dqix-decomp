#include <globaldefs.h>
#pragma optimization_level 4
extern "C" int ReadWordAtOffset0();
extern "C" unsigned int ReadScriptParameterAsInteger(int);
extern "C" void SetWordFieldAtOffset8C(int, unsigned int);
// Original: arm9/main @ 0x0209DB28; symbol: func_0209db28; size: 0x34.
extern "C" int Script_SetWordFieldAtOffset8CWithConvertedParameters(int argument) {
    int object = ReadWordAtOffset0();
    if (object == 0) return 0;
    unsigned int value = ReadScriptParameterAsInteger(argument);
    SetWordFieldAtOffset8C(object, value);
    return 1;
}
