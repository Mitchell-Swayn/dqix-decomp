#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
struct Triple{int x,y,z;};extern "C" void CubicPath_ReadCurrentPosition(void*,unsigned*);extern "C" int AdvanceCubicPathByMinimumDistance(void*);extern "C" void Vector3fix_Subtract(const void*,const void*,void*);extern "C" int fix32_Atan2(int,int);
// Original: arm9/ov001 @ 0x02157AE0; symbol: Graphics_UpdateTrackedHeadingFromPosition; size: 0x114.
extern "C" void CubicPath_AdvanceTrackAndUpdateHeading(char* self,const int* position,int* heading){
if(I(self,0x464)){if(I(self,0x468)){((void(*)(void*))CubicPath_ReadCurrentPosition)(self+0xc8);I(self,0x464)=0;I(self,0x468)=0;}else{((void(*)(void*))CubicPath_ReadCurrentPosition)(self+0xc8);if(AdvanceCubicPathByMinimumDistance(self+0xc8))I(self,0x468)=1;Triple current,delta;CubicPath_ReadCurrentPosition(self+0xc8,(unsigned*)&current);Vector3fix_Subtract(&current,position,&delta);if(delta.x||delta.z){int angle=fix32_Atan2(delta.x,delta.z);int revolutions=(int)((float)angle/4096.0f/6.283185307179586f);int result=angle-(int)(4096.0f*(3.141592653589793f*(2.0f*(float)revolutions)));if(result>0x6487)result-=0x6487;if(result<=0)result+=0x6487;*heading=result;}}}
}
