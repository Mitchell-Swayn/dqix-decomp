#include <globaldefs.h>
// Original data: arm9/main @ 0x20ee800; symbol: data_020ee800.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000002000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee808; symbol: data_020ee808.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4000400020002000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee810; symbol: data_020ee810.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4000200008000800.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee818; symbol: data_020ee818.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000400060006000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextDrawTwoCenteredLinesWithFourGlyphs_UnknownRoleInitializedBytes_Variant3,TextDrawTwoCenteredLinesWithFourGlyphs_UnknownRoleInitializedBytes_Variant2,TextDrawTwoCenteredLinesWithFourGlyphs_UnknownRoleInitializedBytes_Variant4,TextDrawTwoCenteredLinesWithFourGlyphs_UnknownRoleInitializedBytes;struct Glyph {char data[12];};struct Text {char data[12];};extern "C" void TextCanvas_BuildPackedRegionDescriptors(Glyph*,unsigned,void*,void*,void*,void*);extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);extern "C" void TextCanvas_InitializeRegionCanvas(Text*);extern "C" void TextCanvas_SetPixelBuffer(Text*,char*);extern "C" void TextCanvas_SetRegions(Text*,Glyph*,unsigned);extern "C" void TextCanvas_DrawStringAndMeasureAdvance(Text*,short,short,const char*,unsigned,unsigned);
// Original: arm9/main @ 0x020E0CFC; symbol: func_020e0cfc; size: 0xFC.
extern "C" void Text_DrawTwoCenteredLinesWithFourGlyphs(char* self,char* buffer,int offset) {Glyph glyphs[4];Text text;TextCanvas_BuildPackedRegionDescriptors(glyphs,4,&TextDrawTwoCenteredLinesWithFourGlyphs_UnknownRoleInitializedBytes_Variant4,&TextDrawTwoCenteredLinesWithFourGlyphs_UnknownRoleInitializedBytes,&TextDrawTwoCenteredLinesWithFourGlyphs_UnknownRoleInitializedBytes_Variant3,&TextDrawTwoCenteredLinesWithFourGlyphs_UnknownRoleInitializedBytes_Variant2);int width=TextLayout_ComputeWidthWithGlyphSpacing(self+0x6f4,0);int width2=TextLayout_ComputeWidthWithGlyphSpacing(self+0x724,0);TextCanvas_InitializeRegionCanvas(&text);TextCanvas_SetPixelBuffer(&text,buffer+offset);TextCanvas_SetRegions(&text,glyphs,4);TextCanvas_DrawStringAndMeasureAdvance(&text,95-width,20,self+0x6f4,15,0);TextCanvas_DrawStringAndMeasureAdvance(&text,95-width2,44,self+0x724,15,0);}
