#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e7a94; symbol: data_020e7a94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 020000000300000001010101010101010f00.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Glyph {unsigned unknown;signed char width;unsigned char rest[3];};struct Entry {unsigned char bytes[0x17];unsigned char group;Glyph* glyph;};struct Context {unsigned char pad[0x9b8];Entry entries[1];};extern "C" const unsigned TextLayoutDrawCachedGlyphRun_UnknownRoleInitializedBytes[];extern "C" int TextStream_IsControlToken(Context*,unsigned short*);extern "C" int TextLookup_GetKerningAdjustment(unsigned,unsigned,int);
// Original: arm9/main @ 0x02046170; symbol: func_02046170; size: 0x160.
extern "C" int Text_MeasureMaximumEncodedTextLineWidth(Context* context,const unsigned short* text,int length,int font){if(!text)return 0;if(length<0)return 0;unsigned fallback=TextLayoutDrawCachedGlyphRun_UnknownRoleInitializedBytes[font]&255;int width=0,maximum=0;Entry* entry;unsigned previous=255;unsigned newline=0xff01+23,space=0xff01+24;unsigned short code;for(int i=0;i<length;i++){code=text[i];if(code==0xff01)break;if(code==newline){if(maximum<width)maximum=width;width=0;previous=255;}else if(code==space){previous=255;width+=fallback+1;}else if(TextStream_IsControlToken(context,&code)){previous=255;}else{entry=context->entries+code;unsigned current=entry->group;unsigned oldGroup=previous;previous=current;width+=TextLookup_GetKerningAdjustment(oldGroup,current,font);Glyph* glyph=entry->glyph;int glyphWidth=fallback;if(glyph)glyphWidth=glyph->width;width+=glyphWidth+1;}}if(width<maximum)width=maximum;return width;}
