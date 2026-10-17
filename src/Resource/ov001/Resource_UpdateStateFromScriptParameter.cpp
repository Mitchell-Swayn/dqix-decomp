#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct State;
extern "C" char data_02108760[];
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void UpdateResourceStateAndCacheDerivedValue(State *p, int value, short key);
// Original: arm9/ov001 @ 0x02163970; symbol: func_ov001_02163970; size: 0x24.
extern "C" int Resource_UpdateStateFromScriptParameter(IntegerParameterView *parameter) {
    int value = ReadScriptParameterAsInteger(parameter);
    ((void (*)(State *, int, int))UpdateResourceStateAndCacheDerivedValue)((State *)data_02108760, value, value);
    return 1;
}
