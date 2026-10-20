#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Fields{char pad[6];unsigned char state:6;unsigned char spare:2;signed char low:4;signed char action:4;};struct Vec{int x,y,z;};extern "C" int Field_ResolveSynchronizedMonster(void*,void*,int);extern "C" char* Zone3D_GetMainInstance();extern "C" int Zone3D_FindGroundHeightBelowPosition(void*,const void*);extern "C" void _ZN8Vector3iaSERKS_(void*,const void*);extern "C" void SetObjectAngleAndClearFlagC48000(void*,int);extern "C" void Object_InvokeStateMethodAndRecordSuccessfulTransition(void*,int);
// Original: arm9/ov017 @ 0x021C9334; symbol: ApplyResolvedMonsterPositionAngleAndState; size: 0xCC.
extern "C" void Field_ApplyResolvedMonsterPositionAngleAndState(int unused,char* source){unsigned resolved[3];if(!Field_ResolveSynchronizedMonster(source+4,resolved,-1)||W((void*)resolved[2],0x130)==9)return;Vec position={(int)W(source,12),H(source,10)<<4,(int)W(source,16)};int angle=H(source,8);unsigned state=((Fields*)source)->state;char* zone=Zone3D_GetMainInstance();if(U(source,4)==U(zone,0)&&W(zone,0x424)==0)position.y=Zone3D_FindGroundHeightBelowPosition(zone,&position);H((char*)resolved[2],0x166)=((Fields*)source)->action;_ZN8Vector3iaSERKS_((char*)resolved[2]+0x158,&position);SetObjectAngleAndClearFlagC48000((char*)resolved[2],angle);Object_InvokeStateMethodAndRecordSuccessfulTransition((char*)resolved[2],state);}
