#include <globaldefs.h>
ARM
struct IntegerParameterView;struct FloatParameterView;
struct FixedVector { int x,y,z; };
extern "C" char* GetBounded1416ByteRecord(int);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
extern "C" void Util_StoreTaggedTriple(char*,FixedVector);
// Original: arm9/ov001 @ 0x0215C468; symbol: func_ov001_0215c468; size: 0x94.
extern "C" int Resource_SetRecordVectorFromScript(char* args) {
char* record=GetBounded1416ByteRecord(ReadScriptParameterAsInteger((IntegerParameterView*)args));
if(!record) return 0;
FixedVector vector;
vector.x=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+8)));
vector.y=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+16)));
vector.z=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+24)));
Util_StoreTaggedTriple(record,vector);
return 1;
}
