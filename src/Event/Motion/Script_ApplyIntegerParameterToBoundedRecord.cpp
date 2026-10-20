#include <globaldefs.h>
ARM
struct IntegerParameterView { unsigned type; union { int integer; float real; } value; };
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *);
extern "C" char *Event_GetObjectSession(int);
extern "C" void Event_QueueSequenceStop(void *, int);
// Original: arm9/ov001 @ 0x021634A8; symbol: func_ov001_021634a8; size: 0x38.
extern "C" int Script_ApplyIntegerParameterToBoundedRecord(IntegerParameterView *parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    char *record = Event_GetObjectSession(index);
    if (!record) return 0;
    int value = Script_ReadParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
    Event_QueueSequenceStop(record, value);
    return 1;
}
