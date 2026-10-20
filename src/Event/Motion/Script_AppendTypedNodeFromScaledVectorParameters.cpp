#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" int Script_ReadParameterAsInteger(...);
extern "C" float Script_ReadParameterAsFloat(...);
extern "C" char* Event_GetObjectSession(...);
extern "C" void Event_QueueObjectTurn(void*,Triple,int,int);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov001 @ 0x0215C1D0; symbol: Script_AppendTypedNodeFromScaledVectorParameters; size: 0xc8.
// Script AppendTypedNodeFromScaledVectorParameters from listed field operations and calls.
extern "C" bool Script_AppendTypedNodeFromScaledVectorParameters(char* parameters,int count){int b;int index=Script_ReadParameterAsInteger(parameters);Triple vector;vector.x=(int)(4096.0f*Script_ReadParameterAsFloat(parameters+8));vector.y=(int)(4096.0f*Script_ReadParameterAsFloat(parameters+16));vector.z=(int)(4096.0f*Script_ReadParameterAsFloat(parameters+24));int a=Script_ReadParameterAsInteger(parameters+32);b=0;if(count>=6)b=Script_ReadParameterAsInteger(parameters+40);void* record=Event_GetObjectSession(index);if(!record)return false;Event_QueueObjectTurn(record,vector,a,b);return true;}
