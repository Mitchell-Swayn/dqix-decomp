#include <globaldefs.h>
ARM
struct IntegerParameterView;struct FloatParameterView;
struct FixedVector { int x,y,z; };
extern "C" char* Event_GetObjectSession(int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" void Util_StoreTaggedTriple(char*,FixedVector);
// Original: arm9/ov001 @ 0x0215C468; symbol: func_ov001_0215c468; size: 0x94.
extern "C" int Resource_SetRecordVectorFromScript(char* args) {
char* record=Event_GetObjectSession(Script_ReadParameterAsInteger((IntegerParameterView*)args));
if(!record) return 0;
FixedVector vector;
vector.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+8)));
vector.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+16)));
vector.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+24)));
Util_StoreTaggedTriple(record,vector);
return 1;
}
