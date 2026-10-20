#include <globaldefs.h>
struct GlyphWidth { signed char bearing; unsigned char width; signed char advance; };
struct GlyphTable { unsigned char cellWidth,cellHeight; unsigned short stride; unsigned char reserved[3],direction; };
struct FontHeader { unsigned short reserved,fallback; unsigned unknown; GlyphTable* table; };
struct Font { FontHeader* header; };
struct Glyph { const GlyphWidth* metrics; const unsigned char* bitmap; };
struct Renderer;
typedef void (*Draw)(Renderer*,Font*,int,int,unsigned,Glyph*);
struct Renderer { unsigned char reserved[20]; Draw* draw; };
extern "C" unsigned Font_FindGlyphIndexForCharacter(Font*,unsigned);
extern "C" const GlyphWidth* Font_GetGlyphWidthsOrDefault(Font*,unsigned);
// Original: arm9/main @ 0x020B1D70; symbol: func_020b1d70; size: 0x124.
extern "C" int Font_RenderCharacterWithFallback(Renderer* renderer,Font* font,int x,int y,unsigned color,unsigned short character)
{
    unsigned id=Font_FindGlyphIndexForCharacter(font,character);
    if(id==65535) id=font->header->fallback;
    Glyph glyph;
    glyph.metrics=Font_GetGlyphWidthsOrDefault(font,id);
    GlyphTable* table=font->header->table;
    glyph.bitmap=(unsigned char*)table+8+id*table->stride;
    table=font->header->table;
    switch(table->direction) {
    case 0: case 7: x+=glyph.metrics->bearing;break;
    case 1: case 2: x-=table->cellWidth;y+=glyph.metrics->bearing;break;
    case 3: case 4: x-=glyph.metrics->bearing+glyph.metrics->width;y-=table->cellHeight;break;
    case 5: case 6: y-=glyph.metrics->bearing+table->cellHeight;break;
    }
    (*renderer->draw)(renderer,font,x,y,color,&glyph);
    return glyph.metrics->advance;
}
