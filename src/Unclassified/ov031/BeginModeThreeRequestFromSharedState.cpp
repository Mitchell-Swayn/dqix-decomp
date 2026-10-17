#include <globaldefs.h>
ARM
struct Global { void* unused; char* object; };
extern "C" Global data_ov031_02290d18;
extern "C" void func_ov031_022397bc();
extern "C" int BuildModeThreeHalfwordPairAndDispatchRequest(int,int,int,int,unsigned short,unsigned short);
extern "C" void SetStateWithTransitionCallbacks(int);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned);
// Original: arm9/ov031 @ 0x02239724; symbol: func_ov031_02239724; size: 0x98.
extern "C" int BeginModeThreeRequestFromSharedState() {
 char* self=data_ov031_02290d18.object;
 if((unsigned)(*(unsigned*)(self+0x40)-4)<=2) return 1;
 SetStateWithTransitionCallbacks(4);
 self=data_ov031_02290d18.object;
 int result=BuildModeThreeHalfwordPairAndDispatchRequest((int)func_ov031_022397bc,(int)(self+0x1060),(unsigned short)*(unsigned*)(self+0x12a4),(int)(self+0xf80),(unsigned short)*(unsigned*)(self+0x12a0),1);
 if(result==2) return 1;
 SetSharedObjectWord54UnlessStateNineOrTen(result);
 return 0;
}
