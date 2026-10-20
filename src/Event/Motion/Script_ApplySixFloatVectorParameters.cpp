#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
extern "C" void* memset(void*,int,unsigned);
extern "C" float Script_ReadParameterAsFloat(void*);
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void Resource_ScriptEnqueueTypeThreeArgumentRecord(void*,Vec,Vec,int,int,int);
extern "C" void Queue_AppendType14FixedPointCoordinateRecord(void*,int,int,int,int,int,int);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215DD58; symbol: func_ov001_0215dd58; size: 0x180.
extern "C" int Script_ApplySixFloatVectorParameters(char* params,int count) {
 Vec a,b,unused;
 memset(&a,0,12);memset(&b,0,12);memset(&unused,0,12);
 b.x=(int)(4096.0f*Script_ReadParameterAsFloat(params));
 b.y=(int)(4096.0f*Script_ReadParameterAsFloat(params+8));
 b.z=(int)(4096.0f*Script_ReadParameterAsFloat(params+16));
 int x=(int)(4096.0f*Script_ReadParameterAsFloat(params+24));
 int y=(int)(4096.0f*Script_ReadParameterAsFloat(params+32));
 int z=(int)(4096.0f*Script_ReadParameterAsFloat(params+40));
 int option;
 int duration=Script_ReadParameterAsInteger(params+48);
 option=-1;
 if(count>=8)option=Script_ReadParameterAsInteger(params+56);
 Resource_ScriptEnqueueTypeThreeArgumentRecord(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+0x24),a,b,duration,1,0);
 Queue_AppendType14FixedPointCoordinateRecord(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+0x24),x,y,z,duration,option,0);
 return 1;
}
