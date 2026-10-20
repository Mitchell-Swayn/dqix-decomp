#include <globaldefs.h>
ARM
struct FloatParameterView;struct IntegerParameterView;
extern "C" void* memset(void*,int,unsigned);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
struct Vec3 {int x,y,z;};
extern "C" void Resource_ScriptEnqueueTypeThreeArgumentRecord(void*,Vec3,Vec3,int,int,bool);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void* EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215D2CC; symbol: func_ov001_0215d2cc; size: 0x14C.
extern "C" int Script_DispatchFixedPointVectorPair(unsigned char* args,int count) {
 Vec3 first,second;
 memset(&first,0,12);
 memset(&second,0,12);
 first.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)args));
 first.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+8)));
 first.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+16)));
 second.x=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+24)));
 second.y=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+32)));
 second.z=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(args+40)));
 int value=Script_ReadParameterAsInteger((IntegerParameterView*)(args+48));
 bool flag=false;
 if(count>=8) flag=Script_ReadParameterAsInteger((IntegerParameterView*)(args+56))!=0;
 Resource_ScriptEnqueueTypeThreeArgumentRecord(EventGetObjectSession_UnknownRoleZeroInitializedStorage[9],first,second,value,1,flag);
 return 1;
}
