#include <globaldefs.h>
struct InputStateProjection { unsigned char preceding[0x28]; unsigned short x,y; unsigned char middle[6]; unsigned short held; unsigned char tail[4]; unsigned char flag0:1; unsigned char active:1; unsigned char remaining:6;};
struct InputStateOwner {void* preceding; InputStateProjection* state;};
extern "C" InputStateOwner data_ov031_02290d40;
// Original: arm9/ov031 @ 0x0223D49C; symbol: func_ov031_0223d49c; size: 0x88.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM int IsInputPointWithinRectangle(unsigned short* rect) {
 if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15) return 0;
 InputStateProjection* p=data_ov031_02290d40.state;
 if(p->active==0) return 0;
 unsigned int x=p->x; if(rect[0]>x) return 0; if(rect[2]<x) return 0;
 unsigned int y=p->y; if(rect[1]>y) return 0; return rect[3]>=y;
}
