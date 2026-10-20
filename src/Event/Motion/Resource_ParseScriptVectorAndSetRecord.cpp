#include <globaldefs.h>
ARM
struct IntegerParameterView;struct FloatParameterView;
struct FixedVector { int x,y,z; };
extern "C" char* Event_GetObjectSession(int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" void Pool_InitializeNodeFromThreeValues(char*,FixedVector);
// Original: arm9/ov001 @ 0x0215BFD4; symbol: func_ov001_0215bfd4; size: 0x98.
extern "C" int Resource_ParseScriptVectorAndSetRecord(char* args) {
int id=Script_ReadParameterAsInteger((IntegerParameterView*)args);
FixedVector vector;
vector.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+8)));
vector.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+16)));
vector.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+24)));
char* record=Event_GetObjectSession(id);
if(!record) return 0;
Pool_InitializeNodeFromThreeValues(record,vector);
return 1;
}
