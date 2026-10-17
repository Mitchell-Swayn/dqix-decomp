#include <globaldefs.h>
ARM
struct TouchState { unsigned char pad[0x28]; unsigned short x,y; unsigned char pad2[12]; unsigned char low:3; unsigned char active:1; unsigned char high:4; };
extern "C" { extern struct Global { unsigned word; TouchState* state; } data_ov031_02290d40; }
// Original: arm9/ov031 @ 0x0223D5AC; symbol: func_ov031_0223d5ac; size: 0x88.
extern "C" int System_IsTouchInsideRectangle(unsigned short* rect) {
 if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15) return 0;
 TouchState* state=data_ov031_02290d40.state;
 if(!state->active) return 0;
 if(rect[0]>state->x) return 0;
 if(rect[2]<state->x) return 0;
 if(rect[1]>state->y) return 0;
 return rect[3]>=state->y;
}
