#include <globaldefs.h>
ARM
struct InputState { unsigned char pad[0x28]; unsigned short x,y; unsigned char pad2[12]; unsigned char active:1; unsigned char other:7; };
struct InputGlobal { void* unknown; InputState* state; };
extern "C" InputGlobal data_ov031_02290d40;
struct Rect { unsigned short left,top,right,bottom; };
// Original: arm9/ov031 @ 0x0223D414; symbol: func_ov031_0223d414; size: 0x88.
extern "C" int System_IsActiveInputPointWithinRectangle(const Rect* rect) {
 if(((*(volatile unsigned short*)0x027fffa8)&0x8000)>>15) return 0;
 InputState* state=data_ov031_02290d40.state;
 if(!state->active) return 0;
 if(rect->left>state->x) return 0;
 if(rect->right<state->x) return 0;
 if(rect->top>state->y) return 0;
 return rect->bottom>=state->y;
}
