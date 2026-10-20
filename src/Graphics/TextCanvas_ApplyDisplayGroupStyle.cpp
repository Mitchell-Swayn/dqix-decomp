#include <globaldefs.h>
struct Sprite {char pad[10];short x,y,w,h;struct Nibbles {unsigned char low:4,high:4;} nibbles;char pad13[2];unsigned char flags;};
extern "C" void TextCanvas_ConfigureRectangleAndFrame(void*,int,int,int,int,unsigned,unsigned,bool,unsigned);
extern "C" void TextCanvas_DrawBottomCornerSymbols(void*);
extern "C" void TextCanvas_DrawGroupSeparators(void*,void*,Sprite*);
// Original: arm9/main @ 0x02081498; symbol: func_02081498; size: 0x98.
extern "C" void TextCanvas_ApplyDisplayGroupStyle(void* a,void* b,Sprite* p) {TextCanvas_ConfigureRectangleAndFrame(b,p->x,p->y,p->w,p->h,p->nibbles.low,p->nibbles.high,(p->flags&2)!=0,0);if(p->flags&1)TextCanvas_DrawBottomCornerSymbols(b);TextCanvas_DrawGroupSeparators(a,b,p);}
