#include <globaldefs.h>
struct Rectangle { short left,top,right,bottom; };
struct RectangleOwner { unsigned int tag; void* owner; signed char count; char pad9; Rectangle rectangles[3]; short limit; short mask; char pad26[2]; unsigned char state[0x24]; };
extern "C" void WriteFourWords(Rectangle*, short,short,short,short);
extern "C" void WindowControl_InitializeDefaultsAndReset(unsigned char*, int,int);
// Original: arm9/main @ 0x020E15F8; symbol: func_020e15f8; size: 0x7C.
extern "C" void InitializeThreeRectanglesAndMaskedState(RectangleOwner* self, int x,int y) {
    self->tag = 0;
    self->owner = 0;
    self->count = 0;
    for (int i=0;i<3;i++) WriteFourWords(&self->rectangles[i],0,0,0,0);
    self->limit = 0x7fff;
    self->mask = 0xf0a;
    WindowControl_InitializeDefaultsAndReset(self->state,x,y);
}
