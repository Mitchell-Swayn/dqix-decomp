#include <globaldefs.h>
ARM
extern "C" float Script_ReadParameterAsFloat(...);
extern "C" int Script_ReadParameterAsInteger(...);
extern "C" int _ffix(...);
extern "C" int _fmul(...);
extern "C" int Queue_AppendType14FixedPointCoordinateRecord(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov001 @ 0x0215D684; symbol: QueueFixedPointScriptCoordinatesWithOptionalArguments.
extern "C" int Script_QueueCameraOrbitInterpolation(char* args,int count){
int x=(int)(4096.0f*Script_ReadParameterAsFloat(args));int y=(int)(4096.0f*Script_ReadParameterAsFloat(args+8));int z=(int)(4096.0f*Script_ReadParameterAsFloat(args+16));int optional;char* parameter=args+24;args+=32;int value=Script_ReadParameterAsInteger(parameter);optional=-1;if(count>=5){optional=Script_ReadParameterAsInteger(args);args+=8;}int enabled=0;if(count>=6)enabled=Script_ReadParameterAsInteger(args)!=0;Queue_AppendType14FixedPointCoordinateRecord(P(EventGetObjectSession_UnknownRoleZeroInitializedStorage,36),x,y,z,value,optional,enabled);return 1;
}
