#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct IntegerParameterView; struct FloatParameterView;
extern "C" void Memory_AppendInitializedPoolNode(char *, Vector3i, int, int, unsigned);
extern "C" char* Event_GetObjectSession(int i);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView* parameter);
extern "C" unsigned Script_ReadParameterString(void*);
// Original: arm9/ov001 @ 0x0215C994; symbol: func_ov001_0215c994; size: 0xB8.
extern "C" int Script_RequestRecordPositionTransition(char *params, int count) {
    unsigned option;
    int id = Script_ReadParameterAsInteger((IntegerParameterView *)params);
    Vector3i position;
    position.x = (int)(4096.0f * Script_ReadParameterAsFloat((FloatParameterView *)(params + 8)));
    position.z = (int)(4096.0f * Script_ReadParameterAsFloat((FloatParameterView *)(params + 16)));
    position.y = 0xa000;
    int value = Script_ReadParameterAsInteger((IntegerParameterView *)(params + 24));
    option = 0;
    if (count >= 5) option = Script_ReadParameterString(params + 32);
    char *record = Event_GetObjectSession(id);
    int result;
    if (!record) result = 0;
    else { Memory_AppendInitializedPoolNode(record,position,value,1,option); result = 1; }
    return result;
}
