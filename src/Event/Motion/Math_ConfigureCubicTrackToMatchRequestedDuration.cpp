#include <globaldefs.h>
ARM
#pragma opt_dead_assignments off
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
struct Triple{int x,y,z;};extern "C" int Vector3fix_Distance(const void*,const void*);extern "C" void BuildTimedCubicPathCoefficients(void*,void*,int*,int,int);extern "C" void CubicPath_ReadCurrentPosition(void*,unsigned*);extern "C" int Math_AdvanceCubicTrack(void*);extern "C" int fix32_Divide(int,int);
// Original: arm9/ov001 @ 0x021579AC; symbol: Math_ConfigureCubicTrackToMatchRequestedDuration; size: 0x120.
extern "C" int Math_ConfigureCubicTrackToMatchRequestedDuration(char* self){
if(I(self,0xc4)<=0)return 1;int durations[16],distances[16];int i;int total=0;for(i=0;i<I(self,0xc4)-1;++i){distances[i]=Vector3fix_Distance(self+i*12,self+(i+1)*12);total+=distances[i];}for(int i=0;i<I(self,0xc4)-1;++i)durations[i]=I(self,0xc0)/(I(self,0xc4)-1);BuildTimedCubicPathCoefficients(self+0xc8,self,durations,I(self,0xc4),0);int travelled=0;Triple previous,current;for(;;){CubicPath_ReadCurrentPosition(self+0xc8,(unsigned*)&previous);if(Math_AdvanceCubicTrack(self+0xc8))break;CubicPath_ReadCurrentPosition(self+0xc8,(unsigned*)&current);travelled+=Vector3fix_Distance(&previous,&current);}BuildTimedCubicPathCoefficients(self+0xc8,self,durations,I(self,0xc4),fix32_Divide(travelled,I(self,0xc0)<<12));return 0;
}
