#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
struct IntegerParameterView; struct FloatParameterView;
extern "C" void Memory_AppendInitializedPoolNode(char *, Vector3i, int, int, unsigned);
extern "C" char* GetBounded1416ByteRecord(int i);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView* parameter);
extern "C" unsigned OV017_ReadWordField04(void*);
// Original: arm9/ov001 @ 0x0215C994; symbol: func_ov001_0215c994; size: 0xB8.
extern "C" int Script_RequestRecordPositionTransition(char *params, int count) {
    unsigned option;
    int id = ReadScriptParameterAsInteger((IntegerParameterView *)params);
    Vector3i position;
    position.x = (int)(4096.0f * ReadScriptParameterAsFloat((FloatParameterView *)(params + 8)));
    position.z = (int)(4096.0f * ReadScriptParameterAsFloat((FloatParameterView *)(params + 16)));
    position.y = 0xa000;
    int value = ReadScriptParameterAsInteger((IntegerParameterView *)(params + 24));
    option = 0;
    if (count >= 5) option = OV017_ReadWordField04(params + 32);
    char *record = GetBounded1416ByteRecord(id);
    int result;
    if (!record) result = 0;
    else { Memory_AppendInitializedPoolNode(record,position,value,1,option); result = 1; }
    return result;
}
