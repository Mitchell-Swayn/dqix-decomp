#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int ScriptQueryContext_GetActiveInstance(void);
extern "C" int Script_ReadParameterAsInteger(int);
// Original: arm9/main @ 0x0209D770; symbol: func_0209d770; size: 0x3C.
extern "C" int Script_SetFilterContextParameter(int param) {
    int object = ScriptQueryContext_GetActiveInstance();
    if (object == 0) {
        return 0;
    }
    int first = Script_ReadParameterAsInteger(param);
    int second = Script_ReadParameterAsInteger(param + 8);
    *(int *)(object + first * 4 + 0x70) = second;
    return 1;
}
