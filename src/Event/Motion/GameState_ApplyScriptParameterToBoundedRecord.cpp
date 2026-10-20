#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" char* Event_GetObjectSession(int);
extern "C" void Event_QueueHeadingPathPlayback(char*, int);
// Original: arm9/ov001 @ 0x0215C4FC; symbol: func_ov001_0215c4fc; size: 0x48.
extern "C" int GameState_ApplyScriptParameterToBoundedRecord(IntegerParameterView* parameters, int parameterIndex) {
    int recordIndex = Script_ReadParameterAsInteger(parameters);
    char* record = Event_GetObjectSession(recordIndex);
    if (!record) return 0;
    int value = 0;
    if (parameterIndex >= 2)
        value = Script_ReadParameterAsInteger((IntegerParameterView*)((char*)parameters + 8));
    Event_QueueHeadingPathPlayback(record, value);
    return 1;
}
