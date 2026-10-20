#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void _ZN9GameState12SetTimeOfDayE9TimeOfDay(void *, int);
// Original: arm9/ov001 @ 0x02162148; symbol: GameState_SetTimeOfDayFromScriptParameter; size: 0x2C.
// Reads an integer script parameter, sets the GameState time of day, and returns 1.
extern "C" int GameState_SetTimeOfDayFromScriptParameter(void *parameter) {
    void *state = _ZN9GameState11GetInstanceEv();
    int time = Script_ReadParameterAsInteger(parameter);
    _ZN9GameState12SetTimeOfDayE9TimeOfDay(state, time);
    return 1;
}
