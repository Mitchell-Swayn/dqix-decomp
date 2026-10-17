#include <globaldefs.h>

extern "C" int ReadWordAtOffset0();
extern "C" int ReadScriptParameterAsInteger(int value);
extern "C" void FilterDatabaseRecordsByModeAndValue(int object, int first, int second);

// Original: arm9/main @ 0x0209D054; symbol: func_0209d054; size: 0x44.
extern "C" int Script_FilterDatabaseRecordsByModeAndValueWithConvertedParameters(int parameter)
{
    int object = ReadWordAtOffset0();
    if (object == 0) {
        return 0;
    }
    int first = ReadScriptParameterAsInteger(parameter);
    int second = ReadScriptParameterAsInteger(parameter + 8);
    FilterDatabaseRecordsByModeAndValue(object, first, second);
    return 1;
}
