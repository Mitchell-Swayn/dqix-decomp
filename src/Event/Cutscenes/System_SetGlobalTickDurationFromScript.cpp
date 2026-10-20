#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct State;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *ColorAnimation_GetGlobalInstance(void);
extern "C" void ColorAnimation_StartTimedTransition(State *p, unsigned ticks);
// Original: arm9/ov001 @ 0x0215B384; symbol: func_ov001_0215b384; size: 0x28.
extern "C" int System_SetGlobalTickDurationFromScript(IntegerParameterView *parameter) {
    int ticks = Script_ReadParameterAsInteger(parameter);
    State *state = (State *)ColorAnimation_GetGlobalInstance();
    if (state)
        ColorAnimation_StartTimedTransition(state, ticks);
    return 1;
}
