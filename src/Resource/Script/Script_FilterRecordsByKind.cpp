#include <globaldefs.h>
ARM
#pragma optimization_level 3
extern "C" int ScriptQueryContext_GetActiveInstance(void);
extern "C" int ScriptQueryContext_FilterByKind(int, int, int);
extern "C" int Script_ReadParameterAsInteger(void *);
// Original: arm9/main @ 0x0209CE34; symbol: func_0209ce34; size: 0x44.
extern "C" int Script_FilterRecordsByKind(void *param1) {
    int state = ScriptQueryContext_GetActiveInstance();
    if (state == 0) return 0;
    int first = Script_ReadParameterAsInteger(param1);
    int second = Script_ReadParameterAsInteger((char *)param1 + 8);
    ScriptQueryContext_FilterByKind(state, first, second);
    return 1;
}
