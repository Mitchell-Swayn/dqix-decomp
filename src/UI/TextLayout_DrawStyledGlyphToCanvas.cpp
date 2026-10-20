#include <globaldefs.h>
ARM
#pragma force_active on
struct StyledGlyph { const char* text; };
struct StyledEntry { unsigned char unknown[0x18]; StyledGlyph* glyph; };
struct StyledCanvas { unsigned char unknown[0xae]; short tileOriginY; };
struct StyledStream {
    unsigned char unknown0000[0x34]; StyledCanvas* canvas;
    unsigned char unknown0038[0x195b-0x38]; unsigned char style;
    unsigned char unknown195c[0x19dc-0x195c]; unsigned char font;
};
extern "C" {
unsigned TextContext_GetSharedInstance();
void TextCanvas_RenderStyledTextAndMeasure(void*,int,int,const char*,unsigned char,unsigned char,short*,short*,int);
// Original data: arm9/main @ 0x020E7E4C; symbol: data_020e7e4c.
// Four initialized signed16 x offsets for the outline samples: {0,1,1,2}.
extern const short TextLayoutDrawStyledGlyphToCanvas_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/main @ 0x020E7E44; symbol: data_020e7e44.
// Four initialized signed16 y offsets for the outline samples: {1,0,2,1}.
extern const short TextLayoutDrawStyledGlyphToCanvas_UnknownRoleInitializedBytes[];
}

// Original: arm9/main @ 0x020654B8; symbol: func_020654b8; size: 0x218.
// Draws the cached glyph's text into a canvas, including the configured shadow
// or four outline samples, with coordinates relative to the canvas tile origin.
extern "C" void TextLayout_DrawStyledGlyphToCanvas(StyledStream* stream,void* canvas,StyledEntry* entry,int x,short y,unsigned char color) {
    if(entry->glyph) {
        const char* text=entry->glyph->text;
        int targetY=(short)(y-(short)(stream->canvas->tileOriginY*8));
        short width,height;
        StyledStream* shared=(StyledStream*)TextContext_GetSharedInstance();
        if(shared->style&128) {
            for(unsigned char i=0;i<4;++i) {
                TextCanvas_RenderStyledTextAndMeasure(canvas,(short)(x+TextLayoutDrawStyledGlyphToCanvas_UnknownRoleInitializedBytes_Variant2[i]),(short)(targetY+TextLayoutDrawStyledGlyphToCanvas_UnknownRoleInitializedBytes[i]),text,10,1,&width,&height,stream->font);
            }
            TextCanvas_RenderStyledTextAndMeasure(canvas,(short)(x+1),(short)(targetY+1),text,10,color,&width,&height,stream->font);
        } else if(shared->style&2) {
            TextCanvas_RenderStyledTextAndMeasure(canvas,(short)(x+1),(short)(targetY+1),text,10,1,&width,&height,stream->font);
            TextCanvas_RenderStyledTextAndMeasure(canvas,(short)x,(short)targetY,text,10,color,&width,&height,stream->font);
        } else {
            TextCanvas_RenderStyledTextAndMeasure(canvas,x,targetY,text,10,color,&width,&height,stream->font);
        }
    }
}
