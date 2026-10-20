#include <globaldefs.h>
ARM
struct Canvas { unsigned char* pixels; void* rectangles; unsigned char count; };
struct Glyph { unsigned unknown; signed char width; signed char length:6; unsigned char flags:2; short x; };
extern "C" unsigned TextLookup_GetPackedFontMetrics(unsigned char);
extern "C" unsigned int TextLookup_FindGlyphIndexByText(const char*,unsigned char);
extern "C" int TextLookup_GetKerningAdjustment(unsigned char,unsigned char,unsigned char);
extern "C" Glyph* TextLookup_GetGlyphEntryByIndex(unsigned char,unsigned char);
extern "C" void Text_BlitMonochromeGlyphToTiledCanvas(Canvas*,Glyph*,short,short,unsigned char,unsigned char);
// Original: arm9/main @ 0x0205B234; symbol: func_0205b234; size: 0x138.
// Draws each glyph with pair kerning and returns the final horizontal advance.
extern "C" int TextCanvas_DrawStringAndMeasureAdvance(Canvas* canvas,short x,short y,const char* text,unsigned char color,unsigned char font)
{
 if(!canvas->pixels)return 0;
 if(!canvas->rectangles)return 0;
 if(!canvas->count)return 0;
 if(!text)return 0;
 unsigned char previous;
 short pen;
 unsigned char index;
 unsigned char metrics;
 signed char advance;
 int length;
 Glyph* glyph;
 metrics=TextLookup_GetPackedFontMetrics(font);
 pen=x;
 previous=255;
 while(*text){
  advance=metrics+1;
  index=TextLookup_FindGlyphIndexByText(text,font);
  pen+=TextLookup_GetKerningAdjustment(previous,index,font);
  length=1;
  if(index!=255){
   glyph=TextLookup_GetGlyphEntryByIndex(index,font);
   Text_BlitMonochromeGlyphToTiledCanvas(canvas,glyph,pen,y,color,font);
   advance=glyph->width+1;
   length=glyph->length;
  }
  text+=length;
  pen+=advance;
  previous=index;
 }
 return pen-x;
}
