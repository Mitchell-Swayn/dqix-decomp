#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" char* Event_GetObjectSession(int i);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView* parameter);
extern "C" const char* Script_ReadParameterString(void*);
extern "C" void Event_QueueAnimationAfterCurrentStops(void*,const char*,int,int);
struct Param { int words[2]; };
// Original: arm9/ov001 @ 0x0215C788; symbol: func_ov001_0215c788; size: 0x98.
extern "C" int Script_QueueAnimationAfterCurrentStops(Param *params, int count) {
    int scale = 4096;
    int index = Script_ReadParameterAsInteger((IntegerParameterView*)params++);
    const char *name = Script_ReadParameterString(params++);
    int value = 0;
    if (count >= 3) {
        value = Script_ReadParameterAsInteger((IntegerParameterView*)params++);
    }
    if (count >= 4) scale = (int)(4096.0f * Script_ReadParameterAsFloat((FloatParameterView*)params));
    char *record = Event_GetObjectSession(index);
    if (!record) return 0;
    Event_QueueAnimationAfterCurrentStops(record, name, value, scale);
    return 1;
}
