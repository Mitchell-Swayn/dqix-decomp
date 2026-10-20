#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#include <System/Matrix.h>
extern "C" {int Script_ReadParameterAsInteger(void*);char* Event_GetObjectSession(int);int _Z22fix32ReduceAngle0To2Pii(int);int _Z8fix32absi(int);void* memcpy(void*,const void*,unsigned);void Event_QueueObjectTurn(void*,unsigned,unsigned,unsigned,unsigned,unsigned);}
// Original: arm9/ov001 @0x0215c5fc; symbol:Script_QueueTurnTowardReferencedRecord; size:0x110.
// Queues typed rotation payload pointing one referenced record toward another with optional turn direction.
extern "C" int Script_QueueTurnTowardReferencedRecord(unsigned char* params,int count){unsigned char* first=(unsigned char*)Event_GetObjectSession(Script_ReadParameterAsInteger(params));if(!first)return 0;unsigned char* second=(unsigned char*)Event_GetObjectSession(Script_ReadParameterAsInteger(params+8));if(!second)return 0;int dx=W(second,0x74)-W(first,0x74),dz=W(second,0x7c)-W(first,0x7c);Vector3i angles;memcpy(&angles,first+0x80,12);angles.y=_Z22fix32ReduceAngle0To2Pii(fix32_Atan2(dx,dz));int speed=Script_ReadParameterAsInteger(params+16);int direction;if(count>=4)direction=Script_ReadParameterAsInteger(params+24);else{short difference=(short)((short)W(first,0x84)-(short)angles.y);if(_Z8fix32absi(difference)>0x3244)direction=difference<0?1:0;else {if(difference<0)direction=0;else direction=1;}}((void(*)(void*,Vector3i,unsigned,unsigned))Event_QueueObjectTurn)(first,angles,speed,direction);return 1;}
