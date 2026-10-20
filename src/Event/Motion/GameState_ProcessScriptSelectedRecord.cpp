#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" char *Event_GetObjectSession(int index);
extern "C" void Event_QueueAnimationCompletionWait(char *record);
// Original: arm9/ov001 @ 0x0215C3E8; symbol: func_ov001_0215c3e8; size: 0x24.
extern "C" int GameState_ProcessScriptSelectedRecord(IntegerParameterView *parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    char *record = Event_GetObjectSession(index);
    if (!record)
        return 0;
    Event_QueueAnimationCompletionWait(record);
    return 1;
}
