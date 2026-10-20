#include <globaldefs.h>
ARM
#pragma force_active on
struct PrefixDrawGlyph { const char* text; signed char width; };
struct PrefixDrawEntry { unsigned char unknown[0x18]; PrefixDrawGlyph* glyph; };
struct PrefixDisplayRecord { short x,y,width,height; int mode,unknown,scaleX,scaleY,unknown2; };
struct PrefixDisplay { unsigned char unknown[0x440]; PrefixDisplayRecord* active; };
struct PrefixDrawStream {
    unsigned char unknown0000[0x34]; void* canvas;
    unsigned char unknown0038[0x914-0x38];
    PrefixDisplayRecord normalRecord,prefixRecord;
    unsigned char unknown094c[0x9b8-0x94c];
    // Original allocator020459b8 and cache search02045c00 both bound this pool to128 records.
    PrefixDrawEntry entries[128];
    unsigned char unknown17b8[0x187c-0x17b8]; unsigned short color;
    unsigned char unknown187e[4]; unsigned short prefixTokens[64];
    char previousPrefix[64]; unsigned short prefixCount; short prefixWidth;
    unsigned char unknown1946[0x19c3-0x1946]; unsigned char prefixParsed,prefixVisible;
    unsigned char unknown19c5[0x19dc-0x19c5]; unsigned char font;
    unsigned char unknown19dd[3]; PrefixDisplay display;
};
struct StyledStream;
struct StyledEntry;
struct Sprite;
extern "C" {
void TextLayout_GetAnimatedDirectionOffset(unsigned char*,int*,int*);
void TextLayout_ReadDisplayPosition(unsigned char*,short*,short*);
void WindowFrame_SetLinkedPosition(void*,short,short);
void WindowFrame_DrawLinkedScaledRectangle(void*,int,int);
unsigned TextLookup_GetPackedFontMetrics(int);
void TextEntry_SetDrawPositionAndDepth(int,unsigned,unsigned,unsigned short);
void Graphics_DrawTexturedQuadWithVerticalClip(Sprite*,unsigned,int*,unsigned);
void TextLayout_DrawStyledGlyphToCanvas(StyledStream*,void*,StyledEntry*,int,short,unsigned char);
}

// Original: arm9/main @ 0x02066A6C; symbol: func_02066a6c; size: 0x254.
// Draws the retained speaker prefix using its own linked rectangle, then restores
// the message rectangle. Canvas and textured-quad paths share glyph positioning.
extern "C" void TextLayout_DrawRetainedPrefix(PrefixDrawStream* stream,int canvasMode) {
    if(stream->prefixVisible) {
        PrefixDisplay* display=&stream->display;
        unsigned count=0;
        unsigned short* tokens=0;
        if(stream->prefixParsed) {tokens=stream->prefixTokens;count=stream->prefixCount&255;}
        if(tokens) {
            int dx,dy;
            short x,y;
            TextLayout_GetAnimatedDirectionOffset((unsigned char*)stream,&dx,&dy);
            TextLayout_ReadDisplayPosition((unsigned char*)display,&x,&y);
            y-=19;
            display->active=&stream->prefixRecord;
            if(display->active) {
                display->active->scaleX=4096;
                display->active->scaleY=4096;
            }
            if(display->active)display->active->mode=2;
            if(canvasMode)WindowFrame_SetLinkedPosition((unsigned char*)display,x,y);
            else {
                WindowFrame_SetLinkedPosition((unsigned char*)display,(short)(x+dx),(short)(y+dy));
                WindowFrame_DrawLinkedScaledRectangle(display,1,0);
            }
            x+=((short)(8-(stream->prefixWidth&7))+18)>>1;
            y+=5;
            unsigned fallback=TextLookup_GetPackedFontMetrics(stream->font)&255;
            unsigned space=0xff01+24;
            PrefixDrawEntry* entry;
            for(int i=0;i<(int)count;++i) {
                unsigned token=tokens[i];
                if((token&0xff00)==0xff00) {
                    if(token==0xff01)break;
                    if(token==space) {x+=fallback+1;continue;}
                }
                entry=stream->entries+token;
                if(canvasMode)TextLayout_DrawStyledGlyphToCanvas((StyledStream*)stream,stream->canvas,(StyledEntry*)entry,x,y,15);
                else {
                    TextEntry_SetDrawPositionAndDepth((int)entry,x,y,0);
                    Graphics_DrawTexturedQuadWithVerticalClip((Sprite*)entry,stream->color,0,31);
                }
                if(entry->glyph)x+=entry->glyph->width+1;
            }
        }
        display->active=&stream->normalRecord;
    }
}
