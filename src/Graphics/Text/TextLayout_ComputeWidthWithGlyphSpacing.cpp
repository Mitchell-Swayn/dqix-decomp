#include <globaldefs.h>
// Original data: arm9/main @ 0x20e7a94; symbol: data_020e7a94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 020000000300000001010101010101010f00.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Glyph {int unknown;signed char width;signed char advance:6;unsigned char flags:2;};extern "C" unsigned TextLayoutDrawCachedGlyphRun_UnknownRoleInitializedBytes[];extern "C" int TextLookup_FindGlyphIndexByText(const char*,int);extern "C" Glyph* TextLookup_GetGlyphEntryByIndex(int,int);extern "C" int TextLookup_GetKerningAdjustment(unsigned,unsigned,int);
// Original: arm9/main @ 0x020420E8; symbol: func_020420e8; size: 0xA8.
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char* text,int font) {if(!text)return 0;unsigned fallback=TextLayoutDrawCachedGlyphRun_UnknownRoleInitializedBytes[font]&255;unsigned previous=255;unsigned current;int total=0;while(true){if(!*text)break;int width=fallback+1;int id=TextLookup_FindGlyphIndexByText(text,font);if(id<0){previous=255;++text;}else {current=id&255;Glyph* glyph=TextLookup_GetGlyphEntryByIndex(id,font);int spacing=TextLookup_GetKerningAdjustment(previous,current,font);width=glyph->width+1+spacing;text+=glyph->advance;previous=current;}total+=width;}return total-1;}
