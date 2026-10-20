#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov005 @ 0x215ce05; symbol: data_ov005_0215ce05.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 256400.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern "C" {unsigned char* TextContext_GetSharedInstance();int sprintf(char*,const char*,...);void TextLayout_ConvertMarkupToCachedGlyphIndices(void*,const char*,void*,int);void TextWindow_RenderAndTransferDisplayBuffers(void*,int);extern char EquipmentMenuCacheQuantityDigitGlyphs_UnknownRoleInitializedBytes[];}
// Original: arm9/ov005 @ 0x0215A960; symbol: Text_FormatTwentyDecimalDigitTriples; size: 0xe4.
extern "C" void EquipmentMenu_CacheQuantityDigitGlyphs(unsigned char* self){unsigned char* flags;unsigned char* owner=TextContext_GetSharedInstance();flags=owner+0x195b;*flags&=~128;unsigned char* table=self+0x20c;table+=0x3c00;for(int i=0;i<20;++i){for(int j=0;j<3;++j)U(self+i*6+j*2,0x3e0c)=65535;int digit=i%10;char text[4];sprintf(text,EquipmentMenuCacheQuantityDigitGlyphs_UnknownRoleInitializedBytes,digit);TextLayout_ConvertMarkupToCachedGlyphIndices(owner,text,table+i*6,0);if(digit==9){TextWindow_RenderAndTransferDisplayBuffers(owner,0);*flags|=128;}}owner[0x195b]&=~128;}
