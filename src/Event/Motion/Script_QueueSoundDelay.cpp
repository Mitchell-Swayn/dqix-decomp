#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" char *Event_GetObjectSession(int i);
extern "C" void Event_QueueSoundDelay(char *, int);
// Original: arm9/ov001 @ 0x02163438; symbol: func_ov001_02163438; size: 0x38.
extern "C" int Script_QueueSoundDelay(IntegerParameterView *parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    char *record = Event_GetObjectSession(index);
    if (record == 0) {
        return 0;
    }
    int value = Script_ReadParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 8));
    Event_QueueSoundDelay(record, value);
    return 1;
}
