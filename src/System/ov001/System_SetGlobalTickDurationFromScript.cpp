#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct State;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *ReadGlobalValueAt02108D5C(void);
extern "C" void SetTickDurationMillisecondsAndActiveFlags(State *p, unsigned ticks);
// Original: arm9/ov001 @ 0x0215B384; symbol: func_ov001_0215b384; size: 0x28.
extern "C" int System_SetGlobalTickDurationFromScript(IntegerParameterView *parameter) {
    int ticks = ReadScriptParameterAsInteger(parameter);
    State *state = (State *)ReadGlobalValueAt02108D5C();
    if (state)
        SetTickDurationMillisecondsAndActiveFlags(state, ticks);
    return 1;
}
