#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" char *Event_GetObjectSession(int);
extern "C" void Event_QueueSequenceArchivePlayback(void *, int);
// Original: arm9/ov001 @ 0x02163470; symbol: func_ov001_02163470; size: 0x38.
extern "C" int Script_QueueSequenceArchivePlayback(void *parameters) {
    char *record = Event_GetObjectSession(Script_ReadParameterAsInteger(parameters));
    if (record == 0) return 0;
    int value = Script_ReadParameterAsInteger((char *)parameters + 8);
    Event_QueueSequenceArchivePlayback(record, value);
    return 1;
}
