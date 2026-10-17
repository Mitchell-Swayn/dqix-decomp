#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int ReadWordAtOffset0(void);
extern "C" int ReadScriptParameterAsInteger(int);
extern "C" void FilterDatabaseRecordsByCategory(int, int, int);
// Original: arm9/main @ 0x0209D408; symbol: func_0209d408; size: 0x44.
extern "C" int Script_FilterDatabaseRecordsByCategoryWithConvertedParameters(int param_1) {
    int found = ReadWordAtOffset0();
    if (found == 0) return 0;
    int first = ReadScriptParameterAsInteger(param_1);
    int second = ReadScriptParameterAsInteger(param_1 + 8);
    FilterDatabaseRecordsByCategory(found, first, second);
    return 1;
}
