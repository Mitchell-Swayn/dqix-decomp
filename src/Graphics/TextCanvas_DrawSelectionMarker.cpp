#include <globaldefs.h>
ARM
struct TextCanvasPixels;
extern "C" char* TextLayout_GetThirtyTwoByteFontEntry(int);
extern "C" void TextCanvas_BlitMasked4bppPixels(TextCanvasPixels*,const unsigned char*,short,short,short,short,unsigned char,unsigned char);
// Original: arm9/main @ 0x0204FA0C; symbol: TextCanvas_DrawSelectionMarker; size: 0xDC.
// When flag0x40 is set at0xC5, blits glyphs16..19 at four signed-halfword corner coordinates.
extern "C" void TextCanvas_DrawSelectionMarker(TextCanvasPixels* self,short x,short y) {
 if(!(((unsigned char*)self)[0xc5]&0x40))return;
 short left=x-6,top=y-2,right=left+8,bottom=top+8;
 short xs[4]={left,right,left,right};
 short ys[4]={top,top,bottom,bottom};
 unsigned char glyph=16;
 for(unsigned char i=0;i<4;++glyph,++i) {
  char* pixels=TextLayout_GetThirtyTwoByteFontEntry(glyph);
  if(pixels)TextCanvas_BlitMasked4bppPixels(self,(const unsigned char*)pixels,xs[i],ys[i],8,8,0xf0,0x0f);
 }
}
