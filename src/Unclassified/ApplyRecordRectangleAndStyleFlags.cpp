#include <globaldefs.h>
struct Sprite {char pad[10];short x,y,w,h;struct Nibbles {unsigned char low:4,high:4;} nibbles;char pad13[2];unsigned char flags;};
extern "C" void func_0204f174(void*,int,int,int,int,unsigned,unsigned,bool,unsigned);
extern "C" void func_0204fae8(void*);
extern "C" void ProcessEachTableIdentifier(void*,void*,Sprite*);
// Original: arm9/main @ 0x02081498; symbol: func_02081498; size: 0x98.
extern "C" void ApplyRecordRectangleAndStyleFlags(void* a,void* b,Sprite* p) {func_0204f174(b,p->x,p->y,p->w,p->h,p->nibbles.low,p->nibbles.high,(p->flags&2)!=0,0);if(p->flags&1)func_0204fae8(b);ProcessEachTableIdentifier(a,b,p);}
