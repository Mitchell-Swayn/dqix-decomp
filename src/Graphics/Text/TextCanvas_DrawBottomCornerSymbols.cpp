#include <globaldefs.h>
ARM
#pragma force_active on
struct TiledPixelSurface {
    unsigned char prefix[8];
    unsigned char* pixels;
    unsigned char unknown[0x9c];
    short tileWidth, tileHeight;
};
extern "C" void ApplyBitMaskToTiledFourBitPixels(TiledPixelSurface*,const unsigned char*,short,short,short,short,unsigned char,unsigned char);
extern "C" void* TextLookup_FindKeyInPrimaryThenFallbackResource(int,const void*);
// Original data: arm9/main @ 0x020F0303 and 0x020F0306; symbols: data_020f0303, data_020f0306.
// Initialized key bytes: 81 a9 00 at 0x020F0303; 81 a8 00 at 0x020F0306.
// Lookup keys for the two bottom-corner symbols; storage extent remains unresolved.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char TextCanvasDrawBottomCornerSymbols_UnknownRoleInitializedBytes[];
extern "C" unsigned char TextCanvasDrawBottomCornerSymbols_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/main @ 0x0204FAE8; symbol: func_0204fae8; size: 0x110.
// Looks up both corner symbols and masks them into the bottom row with a flag-controlled inset.
extern "C" void TextCanvas_DrawBottomCornerSymbols(void* object)
{
 TiledPixelSurface* canvas=(TiledPixelSurface*)object;
 short x;
 short bottom=(short)(canvas->tileHeight*8)-11;
 x=0;
 short inset=0;
 if(((unsigned char*)object)[0xc5]&16){bottom+=3;inset=3;}
 x+=4;
 x-=inset;
 const unsigned char* mask=(const unsigned char*)TextLookup_FindKeyInPrimaryThenFallbackResource(8,TextCanvasDrawBottomCornerSymbols_UnknownRoleInitializedBytes);
 if(mask)ApplyBitMaskToTiledFourBitPixels(canvas,mask,x,bottom,8,8,240,15);
 x=(short)((short)(canvas->tileWidth*8)-10)+inset;
 mask=(const unsigned char*)TextLookup_FindKeyInPrimaryThenFallbackResource(8,TextCanvasDrawBottomCornerSymbols_UnknownRoleInitializedBytes_Variant2);
 if(mask)ApplyBitMaskToTiledFourBitPixels(canvas,mask,x-1,bottom,8,8,240,15);
}
