#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void _ZN9GameState18SetDayTimerRunningEi(void *gameState, int running);
// Original: arm9/ov001 @ 0x02164080; symbol: func_ov001_02164080; size: 0x34.
extern "C" int GameState_SetDayTimerRunningFromScriptParameter(IntegerParameterView *parameter) {
    int value = ReadScriptParameterAsInteger(parameter);
    void *gameState = _ZN9GameState11GetInstanceEv();
    if (value != 0) {
        _ZN9GameState18SetDayTimerRunningEi(gameState, 0);
    } else {
        _ZN9GameState18SetDayTimerRunningEi(gameState, 1);
    }
    return 1;
}
