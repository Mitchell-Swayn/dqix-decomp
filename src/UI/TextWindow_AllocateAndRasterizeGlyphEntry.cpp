#include <globaldefs.h>
ARM
#pragma force_active on
struct FontGlyphMask;
struct RasterEntry { unsigned char unknown[0x16]; unsigned char flags,tag; FontGlyphMask* glyph; };
struct RasterTexture {
    unsigned char unknown[0x50]; unsigned textureIndex;
    // Texture base uses the low16 bits in units of8 bytes; upper bits are excluded.
    inline unsigned GetTextureByteOffset() const { return (textureIndex<<16)>>13; }
};
struct RasterStream {
    unsigned char unknown0000[0x2cc]; unsigned char claimedTiles[4];
    unsigned char unknown02d0[0x9b8-0x2d0]; RasterEntry entries[128];
    unsigned char references[128];
    unsigned char unknown1838[0x195b-0x1838]; unsigned char style;
    unsigned char unknown195c[0x19cc-0x195c]; unsigned char suppressRaster;
    unsigned char unknown19cd[0x1e28-0x19cd]; RasterTexture* texture;
};
extern "C" {
void* memset(void*,int,unsigned);
int TextLayout_ClaimFreeGlyphBufferSlot(void*,unsigned char*,unsigned);
void Text_DrawClippedGlyphMask4Bpp(short,short,FontGlyphMask*,unsigned char*,int,int,unsigned char,unsigned char);
void TextEntry_InitializeGlyphRenderRecord(char*,unsigned char,int,void*,int,int,unsigned char);
// Original data: arm9/main @ 0x02107800; symbol: data_02107800.
// Opaque fallback storage; this declaration is a non-owning object-representation byte view.
// Only a four-byte pointer read at +0 is independently established here.
// The configured 32-byte symbol span does not establish a logical object extent.
// Debt: recover the complete owning type and migrate every referring translation unit together.
extern unsigned char TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x020E7A8C; symbol: data_020e7a8c.
// Five initialized outline sample colors {1,1,1,1,15}, followed by 3 zero bytes of uncertain role.
extern const unsigned char TextWindowAllocateAndRasterizeGlyphEntry_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x020E7AA6; symbol: data_020e7aa6.
// Initialized signed16 outline x offsets {1,2,2,3,2}.
extern const short TextWindowAllocateAndRasterizeGlyphEntry_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/main @ 0x020E7AB0; symbol: data_020e7ab0.
// The first 5 initialized signed16 y offsets are {2,1,3,2,2}; later data is not consumed here.
extern const short TextWindowAllocateAndRasterizeGlyphEntry_UnknownRoleInitializedBytes_Variant3[];
}

// Original: arm9/main @ 0x020459B8; symbol: func_020459b8; size: 0x248.
// Claims a 128-byte raster tile and a free glyph record, draws the active style,
// then installs the texture/render metadata and initial reference count.
extern "C" int TextWindow_AllocateAndRasterizeGlyphEntry(RasterStream* stream,unsigned char tag,FontGlyphMask* glyph,unsigned char font) {
    int i;
    unsigned char* staging;
    RasterEntry* entry;
    if(!glyph)return 0;
    {
        staging=*(unsigned char**)TextContextGetSharedInstance_UnknownRoleZeroInitializedStorage;
        unsigned char* references=stream->references;
        entry=stream->entries;
        int tile=TextLayout_ClaimFreeGlyphBufferSlot(stream,stream->claimedTiles,4);
        if(tile<0)return 0;
        {
            for(i=0;i<128;++i) {
                if(!references[i]) {
                    if(stream->texture) {
                        entry+=i;
                        bool shadow=false;
                        bool outline=false;
                        staging+=tile*128;
                        if(!stream->suppressRaster) {
                            memset(staging,0,128);
                            if(stream->style&128) {
                                outline=true;
                                for(unsigned char j=0;j<5;++j) {
                                    Text_DrawClippedGlyphMask4Bpp(TextWindowAllocateAndRasterizeGlyphEntry_UnknownRoleInitializedBytes_Variant2[j],TextWindowAllocateAndRasterizeGlyphEntry_UnknownRoleInitializedBytes_Variant3[j],glyph,staging,16,16,TextWindowAllocateAndRasterizeGlyphEntry_UnknownRoleInitializedBytes[j],font);
                                }
                            } else if(stream->style&2) {
                                shadow=true;
                                Text_DrawClippedGlyphMask4Bpp(2,2,glyph,staging,16,16,1,font);
                                Text_DrawClippedGlyphMask4Bpp(1,1,glyph,staging,16,16,15,font);
                            } else {
                                Text_DrawClippedGlyphMask4Bpp(1,1,glyph,staging,16,16,15,font);
                            }
                        }
                        int textureOffset=i*128+stream->texture->GetTextureByteOffset();
                        TextEntry_InitializeGlyphRenderRecord((char*)entry,tag,(int)glyph,staging,tile,textureOffset,font);
                        if(outline)entry->flags|=4;
                        if(shadow)entry->flags|=2;
                    }
                    references[i]=1;
                    return i;
                }
            }
        }
    }
    return 0;
}
