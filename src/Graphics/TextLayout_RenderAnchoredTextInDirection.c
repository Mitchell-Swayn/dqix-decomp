#include <globaldefs.h>
// Community C reference ntrtwl/NitroSystem@d636fb5d2b212e8736f09859fff447be2bd0ac85
// libraries/g2d/src/g2d_TextCanvas.c NNSi_G2dTextCanvasDrawText.
#pragma optimization_level 4
#pragma optimize_for_size off
#pragma always_inline on
typedef struct Font{signed char* info;}Font;typedef struct TextSize{int width,height;}TextSize;typedef struct Direction{signed char x,y;}Direction;
TextSize Font_MeasureMultilineText(Font*,int,int,unsigned);
void Graphics_RenderAlignedTextLinesInDirection(unsigned*,int,int,int,unsigned,unsigned,unsigned,Direction);
static inline TextSize GetFontTextRect(Font* font,int hs,int vs,unsigned text){TextSize result=Font_MeasureMultilineText(font,hs,vs,text);return result;}
static inline TextSize GetTextRect(const unsigned* self,unsigned text){return GetFontTextRect((Font*)self[1],self[2],self[3],text); }
// SDK C aggregate returns preserve the independent measurement and assignment
// objects used by this routine. Compile this translation unit as C.
// Applies horizontal/vertical origins along the supplied signed direction, then
// delegates aligned multiline rendering with the measured width.
// Original: arm9/main @ 0x020B25C4; symbol: func_020b25c4; size: 0x124.
void TextLayout_RenderAnchoredTextInDirection(unsigned* self,int x,int y,int color,unsigned flags,unsigned text,Direction d){
 TextSize area;
 {area=GetTextRect(self,text);
 if(flags&16){const int offset=-(area.width+1)/2;x+=offset*d.x;y+=offset*d.y;}
 else if(flags&32){const int offset=-area.width;x+=offset*d.x;y+=offset*d.y;}
 if(flags&2){const int offset=-(area.height+1)/2;x+=offset*-d.y;y+=offset*d.x;}
 else if(flags&4){const int offset=-area.height;x+=offset*-d.y;y+=offset*d.x;}
 }
 Graphics_RenderAlignedTextLinesInDirection(self,x,y,area.width,color,flags,text,d);
}
