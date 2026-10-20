#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned Event_GetObjectSession(...);
struct Coordinates {int x,y,z;};
extern "C" unsigned Memory_AppendInitializedPoolNode(unsigned,Coordinates,int,int,unsigned);
extern "C" unsigned Script_ReadParameterString(...);
extern "C" float Script_ReadParameterAsFloat(unsigned);
extern "C" unsigned Script_ReadParameterAsInteger(...);
// Original: arm9/ov001 @ 0x0215c06c; symbol: Script_AppendPoolNodeFromFixedPointParameters; size: 0xcc.
extern "C" int Script_QueueObjectPositionInterpolation(unsigned args,int count){
unsigned name;int index;int value;index=Script_ReadParameterAsInteger(args);Coordinates coordinates;coordinates.x=(int)(4096.0f*Script_ReadParameterAsFloat(args+8));coordinates.y=(int)(4096.0f*Script_ReadParameterAsFloat(args+16));coordinates.z=(int)(4096.0f*Script_ReadParameterAsFloat(args+24));value=Script_ReadParameterAsInteger(args+32);name=0;if(count>=6)name=Script_ReadParameterString(args+40);
unsigned pool=Event_GetObjectSession(index);if(!pool)return 0;Memory_AppendInitializedPoolNode(pool,coordinates,value,0,name);return 1;
}