#include <globaldefs.h>
ARM
#pragma opt_rotateloops off
extern "C" void* memcpy(void*,const void*,unsigned);
struct State {char pad[0x50];const unsigned char* text;char pad2[0x1810];int lineHeight;char pad3[0x174];unsigned char font;};
struct Glyph {char pad[5];signed char length:6;};
extern "C" Glyph* TextLookup_FindMatchingByteKeyEntry(const unsigned char*,unsigned char);
extern "C" void TextWindow_SetViewportRectangle(State*,int,int,int,int);
// Original: arm9/main @ 0x0206B6B8; symbol: func_0206b6b8; size: 0xF8.
extern "C" void TextLayout_CenterDisplayRectangleForLineCount(State* p){
 const unsigned char* cursor=p->text;int count=0;unsigned end=0xff01,skip1=end+11,skip2=end+12,newline=end+23;
 unsigned short code,token;
 for(;;){if(*cursor==0)break;memcpy(&token,cursor,2);if((token&0xff00)==0xff00){memcpy(&code,cursor,2);if(code==end||code==skip1||code==skip2)break;if(code==newline)++count;cursor+=2;}
 else {int length=1;Glyph* g=TextLookup_FindMatchingByteKeyEntry(cursor,p->font);if(g)length=g->length;cursor+=length;}}
 int y=((192-((count-1)*p->lineHeight+8))>>1)-16;
 TextWindow_SetViewportRectangle(p,2,y,252,192-y);
}
