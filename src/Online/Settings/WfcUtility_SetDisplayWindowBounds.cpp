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
#pragma always_inline on
inline void WriteBounds(volatile unsigned short* out,const unsigned short* p){unsigned x=p[0],y=p[1],right=p[2],bottom=p[3];out[0]=((x<<8)&0xff00)|(right&255);out[2]=((y<<8)&0xff00)|(bottom&255);}
// Original: arm9/ov031 @ 0x0223CC18; symbol: Graphics_WriteWindowBoundsForDisplay; size: 0x118.
extern "C" void WfcUtility_SetDisplayWindowBounds(int engine,int window,const unsigned short* bounds){
if(engine==1){if(!window)WriteBounds((volatile unsigned short*)0x04001040,bounds);else WriteBounds((volatile unsigned short*)0x04001042,bounds);}else{if(!window)WriteBounds((volatile unsigned short*)0x04000040,bounds);else WriteBounds((volatile unsigned short*)0x04000042,bounds);}
}
