#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20ee82c; symbol: data_020ee82c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00002000400060008000a000c000.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee83a; symbol: data_020ee83a.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1000100010001000100010001000.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee848; symbol: data_020ee848.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000000000000000.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee856; symbol: data_020ee856.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2000200020002000200020002000.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char SubMapDisplayDrawPairedLabelStrings_UnknownRoleInitializedBytes[],SubMapDisplayDrawPairedLabelStrings_UnknownRoleInitializedBytes_Variant3[],SubMapDisplayDrawPairedLabelStrings_UnknownRoleInitializedBytes_Variant4[],SubMapDisplayDrawPairedLabelStrings_UnknownRoleInitializedBytes_Variant2[];extern "C" void TextCanvas_BuildPackedRegionDescriptors(void*,int,const void*,const void*,const void*,const void*);extern "C" void TextCanvas_InitializeRegionCanvas(void*);extern "C" void TextCanvas_SetPixelBuffer(void*,int);extern "C" void TextCanvas_SetRegions(void*,void*,int);extern "C" int TextCanvas_DrawStringAndMeasureAdvance(void*,int,int,void*,int,int);
// Original: arm9/main @ 0x020E0DF8; symbol: func_020e0df8; size: 0xCC.
extern "C" void SubMapDisplay_DrawPairedLabelStrings(unsigned char* object,int a,int b){unsigned char entries[84];unsigned state[3];TextCanvas_BuildPackedRegionDescriptors(entries,7,SubMapDisplayDrawPairedLabelStrings_UnknownRoleInitializedBytes,SubMapDisplayDrawPairedLabelStrings_UnknownRoleInitializedBytes_Variant3,SubMapDisplayDrawPairedLabelStrings_UnknownRoleInitializedBytes_Variant4,SubMapDisplayDrawPairedLabelStrings_UnknownRoleInitializedBytes_Variant2);TextCanvas_InitializeRegionCanvas(state);TextCanvas_SetPixelBuffer(state,a+b);TextCanvas_SetRegions(state,entries,7);int last=TextCanvas_DrawStringAndMeasureAdvance(state,6,2,object+0x5b4,15,0);TextCanvas_DrawStringAndMeasureAdvance(state,(short)(last+9),2,object+0x5f4,15,0);}
