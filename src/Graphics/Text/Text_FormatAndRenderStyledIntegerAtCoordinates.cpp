#include <globaldefs.h>
ARM
#include <std_library_functions.h>
// Original data: arm9/main @ 0x20f1217; symbol: data_020f1217.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2564000000.
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void __clear(void*,int);extern char Text_FormatAndRenderStyledIntegerAtCoordinates_Format02D[],Text_FormatAndRenderStyledIntegerAtCoordinates_Format04D[],TextFormatAndRenderStyledIntegerAtCoordinates_UnknownRoleInitializedBytes[];int TextLayout_ComputeWidthWithGlyphSpacing(char*,int);void TextCanvas_RenderStyledTextAndMeasure(void*,short,int,char*,int,unsigned char,short*,short*,int);
// Original: arm9/main @ 0x0208D42C; symbol: func_0208d42c; size: 0xF0.
void Text_FormatAndRenderStyledIntegerAtCoordinates(int unused,void* object,int x,int y,int value,unsigned char style,unsigned char mode,unsigned char centered,unsigned char tagged){if(!object)return;char text[8];short b,a;int offset=0;__clear(text,8);if(tagged){if(mode==2)sprintf(text,Text_FormatAndRenderStyledIntegerAtCoordinates_Format02D,value);else sprintf(text,Text_FormatAndRenderStyledIntegerAtCoordinates_Format04D,value);}else sprintf(text,TextFormatAndRenderStyledIntegerAtCoordinates_UnknownRoleInitializedBytes,value);if(centered)offset=(short)-TextLayout_ComputeWidthWithGlyphSpacing(text,0);TextCanvas_RenderStyledTextAndMeasure(object,(short)(x+offset),y,text,8,style,&b,&a,0);}}
