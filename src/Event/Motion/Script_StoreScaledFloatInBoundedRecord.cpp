#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" char* Event_GetObjectSession(int);
extern "C" void Event_QueueObjectRadius(char*, int);
// Original: arm9/ov001 @ 0x0215C858; symbol: func_ov001_0215c858; size: 0x4C.
extern "C" int Script_StoreScaledFloatInBoundedRecord(IntegerParameterView* parameters) {
    int index = Script_ReadParameterAsInteger(parameters);
    char* record = Event_GetObjectSession(index);
    if (record == 0) return 0;
    float value = Script_ReadParameterAsFloat((FloatParameterView*)((char*)parameters + 8));
    Event_QueueObjectRadius(record, (int)(value * 4096.0f));
    return 1;
}
