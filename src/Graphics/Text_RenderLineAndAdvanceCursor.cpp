#include <globaldefs.h>
ARM
struct Renderer;
struct Font { void* header; unsigned short(*read)(unsigned*); };
struct Layout { Renderer* renderer;Font* font;int spacing; };
struct Direction { signed char x,y; };
extern "C" int Font_RenderCharacterWithFallback(Renderer*,Font*,int,int,unsigned,unsigned short);
// Original: arm9/main @ 0x020B23A8; symbol: func_020b23a8; size: 0xB4.
extern "C" void Text_RenderLineAndAdvanceCursor(Layout* layout,int x,int y,unsigned color,unsigned cursor,unsigned* next,Direction direction) {
int spacing=layout->spacing;
Font* font=layout->font;
unsigned position=cursor;
unsigned short(*read)(unsigned*)=font->read;
unsigned short character=read(&position);
if(character)do {
if(character==10)break;
int advance=spacing+Font_RenderCharacterWithFallback(layout->renderer,font,x,y,color,character);
x+=advance*direction.x;y+=advance*direction.y;
character=read(&position);
}while(character);
if(next)*next=character==10?position:0;
}
