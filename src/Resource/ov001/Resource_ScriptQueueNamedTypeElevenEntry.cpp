#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" char* GetBounded1416ByteRecord(int i);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView* parameter);
extern "C" const char* OV017_ReadWordField04(void*);
extern "C" void func_ov001_0215a594(void*,const char*,int,int);
struct Param { int words[2]; };
// Original: arm9/ov001 @ 0x0215C788; symbol: func_ov001_0215c788; size: 0x98.
extern "C" int Resource_ScriptQueueNamedTypeElevenEntry(Param *params, int count) {
    int scale = 4096;
    int index = ReadScriptParameterAsInteger((IntegerParameterView*)params++);
    const char *name = OV017_ReadWordField04(params++);
    int value = 0;
    if (count >= 3) {
        value = ReadScriptParameterAsInteger((IntegerParameterView*)params++);
    }
    if (count >= 4) scale = (int)(4096.0f * ReadScriptParameterAsFloat((FloatParameterView*)params));
    char *record = GetBounded1416ByteRecord(index);
    if (!record) return 0;
    func_ov001_0215a594(record, name, value, scale);
    return 1;
}
