#include <globaldefs.h>
// Original data: arm9/main @ 0x20ee864; symbol: data_020ee864.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000400080000000200040006000800000002000400060008000.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee87e; symbol: data_020ee87e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000002000200020002000200030003000300030003000.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee898; symbol: data_020ee898.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4000400010002000200020002000100020002000200020001000.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee8b2; symbol: data_020ee8b2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2000200020001000100010001000100008000800080008000800.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextRenderThreeNamesUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant3[],TextRenderThreeNamesUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant4[],TextRenderThreeNamesUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes[],TextRenderThreeNamesUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant2[];
extern "C" void TextCanvas_BuildPackedRegionDescriptors(void*,unsigned int,void*,void*,void*,void*);
extern "C" void TextCanvas_InitializeRegionCanvas(void*),TextCanvas_SetPixelBuffer(void*,char*),TextCanvas_SetRegions(void*,void*,unsigned char);
extern "C" int TextCanvas_DrawStringAndMeasureAdvance(void*,short,short,const char*,unsigned int,unsigned int);
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
struct Name {char text[0x48];};
struct Number {char text[8];};
struct Owner {char pad[0x5fc];Name names[3];Number numbers[3];};
// Original: arm9/main @ 0x020E0B4C; symbol: func_020e0b4c; size: 0x1B0.
extern "C" ARM void Text_RenderThreeNamesUsingGeneratedGlyphDescriptors(Owner* self,char* buffer,int offset) {
 char entries[156];unsigned int transfer[3];
 TextCanvas_BuildPackedRegionDescriptors(entries,13,TextRenderThreeNamesUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes,TextRenderThreeNamesUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant2,TextRenderThreeNamesUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant3,TextRenderThreeNamesUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant4);
 TextCanvas_InitializeRegionCanvas(transfer);TextCanvas_SetPixelBuffer(transfer,buffer+offset);TextCanvas_SetRegions(transfer,entries,13);
 for(int i=0;i<3;++i) {
  const char* text;
  int rowOffset=i*13;int y=rowOffset+16;TextCanvas_DrawStringAndMeasureAdvance(transfer,10,(short)y,self->names[i].text,15,0);
  text=self->numbers[i].text;
  if(String_CountBytesUntilTerminator(text)==3)TextCanvas_DrawStringAndMeasureAdvance(transfer,0x74,(short)y,text,15,0);
  else if(String_CountBytesUntilTerminator(text)==2)TextCanvas_DrawStringAndMeasureAdvance(transfer,0x78,(short)y,text,15,0);
  else if(String_CountBytesUntilTerminator(text)==1)TextCanvas_DrawStringAndMeasureAdvance(transfer,0x7d,(short)(rowOffset+15),text,15,0);
  else TextCanvas_DrawStringAndMeasureAdvance(transfer,0x74,(short)y,text,15,0);
 }
}
