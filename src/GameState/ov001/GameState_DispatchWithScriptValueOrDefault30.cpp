#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct State;
extern "C" State data_02109bf4;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(int param_1, unsigned int param_2, unsigned int unused3, unsigned int unused4);
// Original: arm9/ov001 @ 0x0216393C; symbol: func_ov001_0216393c; size: 0x2C.
extern "C" int GameState_DispatchWithScriptValueOrDefault30(IntegerParameterView *parameter, int useParameter) {
    unsigned int value = 0x1e;
    if (useParameter > 0)
        value = ReadScriptParameterAsInteger(parameter);
    ((void (*)(int, unsigned int))DispatchObjectStateOneOrTwoUnlessFlag4)((int)&data_02109bf4, value);
    return 1;
}
