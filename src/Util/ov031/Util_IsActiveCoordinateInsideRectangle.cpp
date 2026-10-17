#include <globaldefs.h>
ARM
struct CoordinateState {unsigned char pad[0x28];unsigned short x,y;unsigned char pad2[0xc];unsigned char b0:2;unsigned char active:1;unsigned char b1:5;};
struct Globals {int unknown;CoordinateState* state;};
extern "C" Globals data_ov031_02290d40;
// Original: arm9/ov031 @ 0x0223D524; symbol: func_ov031_0223d524; size: 0x88.
extern "C" int Util_IsActiveCoordinateInsideRectangle(unsigned short* rect){
 if((*(volatile unsigned short*)0x027fffa8 & 0x8000)>>15)return 0;
 CoordinateState* p=data_ov031_02290d40.state;
 if(!p->active)return 0;
 if(rect[0]>p->x)return 0;
 if(rect[2]<p->x)return 0;
 if(rect[1]>p->y)return 0;
 return rect[3]>=p->y;
}
