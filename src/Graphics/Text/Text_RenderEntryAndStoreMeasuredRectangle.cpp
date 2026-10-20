#include <globaldefs.h>
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(void*,unsigned char);extern "C" void Window_SetTextHitRectangle(void*,int,int,int,int);extern "C" void TextCanvas_DrawStringAndMeasureAdvance(void*,int,int,void*,unsigned char,unsigned char);
struct Parent{unsigned pad;void* object;};struct Object{unsigned pad;Parent* parent;signed char count;char pad2;char entries[24];};
// Original: arm9/main @ 0x020E2310; symbol: func_020e2310; size: 0xB0.
extern "C" ARM void Text_RenderEntryAndStoreMeasuredRectangle(Object* p,int index,int x,int y,void* value,unsigned char a,unsigned char b){if(index>=0 && index<3){int width=TextLayout_ComputeWidthWithGlyphSpacing(value,b);Window_SetTextHitRectangle(p->entries+index*8,(short)x,(short)y,(short)(x+width),(short)(y+12));}if(p->count<=index)p->count=index+1;TextCanvas_DrawStringAndMeasureAdvance(p->parent->object,(short)x,(short)y,value,a,b);}
