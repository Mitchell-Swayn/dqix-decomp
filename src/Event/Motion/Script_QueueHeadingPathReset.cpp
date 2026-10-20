#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" char *Event_GetObjectSession(int);
extern "C" void Event_QueueHeadingPathReset(void *);
// Original: arm9/ov001 @ 0x0215C40C; symbol: func_ov001_0215c40c; size: 0x24.
extern "C" int Script_QueueHeadingPathReset(void *parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    char *record = Event_GetObjectSession(index);
    if (!record) return 0;
    Event_QueueHeadingPathReset(record);
    return 1;
}
