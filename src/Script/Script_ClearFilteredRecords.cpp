#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int ScriptQueryContext_GetActiveInstance(void);
extern "C" void ScriptQueryContext_ClearFilteredRecords(int);
// Original: arm9/main @ 0x0209CE14; symbol: func_0209ce14; size: 0x20.
extern "C" int Script_ClearFilteredRecords(void) {
    int value = ScriptQueryContext_GetActiveInstance();
    if (value != 0) {
        ScriptQueryContext_ClearFilteredRecords(value);
        return 1;
    }
    return 0;
}
