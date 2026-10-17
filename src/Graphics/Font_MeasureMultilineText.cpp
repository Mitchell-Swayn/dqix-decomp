#include <globaldefs.h>
ARM
struct Font { signed char* info; };
struct TextSize { int width,height; };
extern "C" int Font_ComputeLineWidthUntilNewline(Font*,int,unsigned int,unsigned int*);
// Original: arm9/main @ 0x020B1020; symbol: func_020b1020; size: 0x94.
extern "C" TextSize Font_MeasureMultilineText(Font* font,int spacing,int lineSpacing,unsigned int cursor) {
TextSize size={0,0};
int lines=1;
if(cursor)do {
int width=Font_ComputeLineWidthUntilNewline(font,spacing,cursor,&cursor);
if(width>size.width)size.width=width;
++lines;
}while(cursor);
size.height=(lines-1)*(lineSpacing+font->info[1])-lineSpacing;
return size;
}
