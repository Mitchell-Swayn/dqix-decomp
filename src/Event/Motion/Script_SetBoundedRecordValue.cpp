#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void* parameter);
extern "C" char* Event_GetObjectSession(int index);
extern "C" void Event_QueueHeadingPathDuration(char* record, int value);
// Original: arm9/ov001 @ 0x0215C430; symbol: func_ov001_0215c430; size: 0x38.
extern "C" int Script_SetBoundedRecordValue(void* parameters) {
    int index = Script_ReadParameterAsInteger(parameters);
    char* record = Event_GetObjectSession(index);
    if (record == 0) return 0;
    int value = Script_ReadParameterAsInteger((char*)parameters + 8);
    Event_QueueHeadingPathDuration(record, value);
    return 1;
}
