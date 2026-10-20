#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextLayout_DrawCachedGlyphRun(unsigned,void*,short,int,unsigned short,int,int,int,int,int);
// Original: arm9/ov005 @ 0x02155258; symbol: func_ov005_02155258; size: 0x15C.
// Draws decimal tens/ones glyphs with one-pixel corrections for digit one.
extern "C" void DrawTwoDecimalDigitGlyphs(char* p,int value,short x,int y,unsigned short color){
 unsigned owner=TextContext_GetSharedInstance();
 volatile unsigned* port=(volatile unsigned*)0x04000444;
 port[0]=0;port[47]=1;port[11]=0;port[11]=0;port[11]=0xffc01000;
 int tens=value/10;int ones=value%10;
 short dx=x;
 if(tens){
  if(ones==1)dx=x+1;
  if(tens==1)dx++;
  TextLayout_DrawCachedGlyphRun(owner,p+0x3e0c+tens*6,dx,y,color,8,0,0,0,17);
 }
 dx=x+5;if(ones==1)dx++;
 TextLayout_DrawCachedGlyphRun(owner,p+0x3e0c+ones*6,dx,y,color,8,0,0,0,17);
 *(volatile unsigned*)0x04000504=0;
 *(volatile unsigned*)0x04000448=1;
}
