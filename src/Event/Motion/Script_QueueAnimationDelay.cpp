#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *);
extern "C" char *Event_GetObjectSession(int);
extern "C" void Event_QueueAnimationDelay(void *, int);
// Original: arm9/ov001 @ 0x0215C544; symbol: func_ov001_0215c544; size: 0x38.
extern "C" int Script_QueueAnimationDelay(IntegerParameterView *parameter) {
    char *record = Event_GetObjectSession(Script_ReadParameterAsInteger(parameter));
    if (record == 0) return 0;
    int value = Script_ReadParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
    Event_QueueAnimationDelay(record, value);
    return 1;
}
