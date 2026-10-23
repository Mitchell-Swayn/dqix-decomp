#include <globaldefs.h>
ARM
#pragma force_active on

struct DecodeGlyph { const char* text; signed char width; signed char length:6; unsigned char flags:2; };
struct DecodeStream {
    unsigned char unknown0000[0x4c];
    unsigned short* tokens;
    const char* encoded;
    const char* sourceStart;
    const char* sourceCursor;
    unsigned char unknown005c[0x6c-0x5c];
    unsigned decodedCount, tokenCount;
    unsigned unknown0074, unknown0078, sourceOffset;
    unsigned char unknown0080[0x934-0x80];
    short prefixWindowWidth,prefixWindowHeight;
    unsigned char unknown0938[0x9b4-0x938];
    unsigned allocatedCount;
    unsigned char glyphEntries[0xe00];
    unsigned char references[128];
    unsigned char unknown1838[0x1882-0x1838];
    unsigned short prefixTokens[64];
    char previousPrefix[64];
    unsigned short prefixCount;
    short prefixWidth,prefixEnd;
    unsigned char unknown1948[0x19c2-0x1948];
    unsigned char prefixClosed,prefixParsed,prefixVisible;
    unsigned char unknown19c5[0x19dc-0x19c5];
    unsigned char font;
    // Retained-prefix token storage is a64-slot ring; preserve the two narrow writes.
    inline void AdvancePrefixCount() { ++prefixCount; prefixCount&=63; }
};
struct RasterStream;
struct FontGlyphMask;
extern "C" {
void* memcpy(void*,const void*,unsigned);
bool TextStream_IsControlToken(int,void*);
int TextStream_GetExtendedControlArgumentCount(void*,const void*);
char* TextLookup_FindMatchingByteKeyEntry(const void*,int);
int TextLookup_FindGlyphIndexByText(const void*,int);
int TextEntry_FindCachedGlyphForCurrentStyle(unsigned char*,unsigned);
int TextWindow_AllocateAndRasterizeGlyphEntry(RasterStream*,unsigned char,FontGlyphMask*,unsigned char);
int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
// Original data: arm9/main @ 0x020F08DC; symbol: data_020f08dc.
// Initialized bytes {0x2f,0x2f,0}: the two-byte // prefix delimiter and terminator.
extern const char TextLayoutWrapEncodedTextToPixelWidth_UnknownRoleInitializedBytes_Variant2[];
}

// Original: arm9/main @ 0x02067B28; symbol: func_02067b28; size: 0x330.
// Decodes stream tokens, reuses cached styled glyphs, and retains references for
// the prefix before its delimiter. A newly rasterized glyph ends this update.
extern "C" void TextStream_DecodeGlyphsAndTrackPrefixReferences(DecodeStream* stream) {
    if(!stream->sourceStart || !stream->sourceCursor || stream->tokenCount<=stream->decodedCount)return;
    DecodeGlyph* glyph;
    int count;
    while(stream->decodedCount<stream->tokenCount) {
        const char* source=stream->encoded+stream->sourceOffset;
        unsigned short* output=stream->tokens+stream->decodedCount;
        unsigned short token;
        memcpy(&token,source,2);
        if(TextStream_IsControlToken((int)stream,&token)) {
            *output=token;
            stream->sourceOffset+=2;
            ++stream->decodedCount;
            count=TextStream_GetExtendedControlArgumentCount(stream,&token);
            memcpy(output+1,source+2,count*2);
            stream->sourceOffset+=count*2;
            stream->decodedCount+=count;
        } else {
            if(!stream->prefixClosed) {
                stream->prefixVisible=1;
                if(stream->prefixEnd<=0)stream->prefixVisible=0;
                if(!RuntimeMemory_CompareByteRanges(source,TextLayoutWrapEncodedTextToPixelWidth_UnknownRoleInitializedBytes_Variant2,2)) {
                    if(!stream->prefixCount)stream->prefixVisible=0;
                    else {
                        stream->prefixWindowWidth=stream->prefixWidth+18+(short)(8-(stream->prefixWidth&7));
                        stream->prefixWindowHeight=22;
                        stream->prefixClosed=1;
                    }
                    stream->prefixParsed=1;
                }
            }
            glyph=(DecodeGlyph*)TextLookup_FindMatchingByteKeyEntry(source,stream->font);
            int glyphIndex=TextLookup_FindGlyphIndexByText(source,stream->font);
            if(glyph && glyphIndex>=0) {
                int cached=TextEntry_FindCachedGlyphForCurrentStyle((unsigned char*)stream,(unsigned)glyph);
                stream->sourceOffset+=glyph->length;
                if(cached<0) {
                    unsigned short created=TextWindow_AllocateAndRasterizeGlyphEntry((RasterStream*)stream,glyphIndex&255,(FontGlyphMask*)glyph,stream->font);
                    if(!stream->prefixClosed)stream->prefixTokens[stream->prefixCount]=created;
                    *output=created;
                    ++stream->decodedCount;
                    stream->allocatedCount=(stream->allocatedCount+1)&127;
                    break;
                }
                unsigned short index=cached;
                if(!stream->prefixClosed) {
                    stream->prefixTokens[stream->prefixCount]=index;
                    stream->AdvancePrefixCount();
                }
                *output=index;
                if(stream->references[index]<255)++stream->references[index];
            } else {
                char byte=*source;
                if(!stream->prefixClosed && byte==' ') {
                    stream->prefixTokens[stream->prefixCount]=0xff19;
                    stream->AdvancePrefixCount();
                }
                *output=0xff19;
                ++stream->sourceOffset;
            }
            ++stream->decodedCount;
        }
    }
    if(!stream->prefixClosed) {
        ++stream->prefixCount;
        stream->prefixCount&=63;
    }
}
