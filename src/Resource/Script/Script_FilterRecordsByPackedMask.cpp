#include <globaldefs.h>
#pragma optimization_level 4
extern "C" int ReadWordAtOffset0();
extern "C" unsigned int ReadScriptParameterAsInteger(int);
extern "C" void FilterSixtyFourByteRecordsByWordMask(int, unsigned int, unsigned int);
// Original: arm9/main @ 0x0209D098; symbol: func_0209d098; size: 0x44.
extern "C" int Script_FilterRecordsByPackedMask(int argument) {
    int object = ReadWordAtOffset0();
    if (object == 0) return 0;
    unsigned int value = ReadScriptParameterAsInteger(argument);
    unsigned int value2 = ReadScriptParameterAsInteger(argument + 8);
    FilterSixtyFourByteRecordsByWordMask(object, value, value2);
    return 1;
}
