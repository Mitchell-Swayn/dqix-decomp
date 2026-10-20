#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" char *Event_GetObjectSession(int);
extern "C" void Event_QueueAlphaDelay(void *, int);
// Original: arm9/ov001 @ 0x0215C820; symbol: func_ov001_0215c820; size: 0x38.
extern "C" bool Script_QueueAlphaDelay(void *parameter) {
    int id = Script_ReadParameterAsInteger(parameter);
    char *record = Event_GetObjectSession(id);
    if (record == 0) return false;
    int value = Script_ReadParameterAsInteger((unsigned char *)parameter + 8);
    Event_QueueAlphaDelay(record, value);
    return true;
}
