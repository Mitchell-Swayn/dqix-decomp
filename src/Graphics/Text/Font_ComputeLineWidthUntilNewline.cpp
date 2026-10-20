#include <globaldefs.h>
struct FontHeader { unsigned short reserved, fallback; };
struct Font { FontHeader* header; int (*read)(unsigned*); };
struct GlyphWidth { signed char bearing; unsigned char width; signed char advance; };
extern "C" unsigned Font_FindGlyphIndexForCharacter(Font*, unsigned);
extern "C" const GlyphWidth* Font_GetGlyphWidthsOrDefault(Font*,unsigned);
// Original: arm9/main @ 0x020B0F00; symbol: func_020b0f00; size: 0xAC.
extern "C" int Font_ComputeLineWidthUntilNewline(Font* font,int spacing,unsigned cursor,unsigned* next)
{
    unsigned position=cursor;
    int width=0;
    int (*read)(unsigned*)=font->read;
    int character=read(&position);
    if(character) do {
        if(character==10) break;
        unsigned id=Font_FindGlyphIndexForCharacter(font,character);
        if(id==65535) id=font->header->fallback;
        const GlyphWidth* glyph=Font_GetGlyphWidthsOrDefault(font,id);
        width+=spacing+glyph->advance;
        character=read(&position);
    } while(character);
    if(next) *next=character==10?position:0;
    if(width>0) width-=spacing;
    return width;
}
