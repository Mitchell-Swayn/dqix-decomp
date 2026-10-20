#include <globaldefs.h>
ARM
#include <std_library_functions.h>
// Original data: arm9/main @ 0x20f0300; symbol: data_020f0300.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 256400.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void __clear(void*,unsigned);extern "C" unsigned TextLookup_SelectFontTableForFont(unsigned char);extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(void*,unsigned);extern "C" void TextCanvas_RenderStyledTextAndMeasure(void*,int,int,void*,unsigned,unsigned,void*,void*,unsigned);extern "C" char TextCanvas_FormatAndRenderSignedPaddedInteger_Format0Dd[],TextCanvas_FormatAndRenderSignedPaddedInteger_FormatD[],TextCanvasFormatAndRenderSignedPaddedInteger_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x0204F7E8; symbol: func_0204f7e8; size: 0x12C.
extern "C" void TextCanvas_FormatAndRenderSignedPaddedInteger(void* p,int x,int y,int number,unsigned char a,unsigned char b,void* c,void* d,unsigned char right,unsigned char width,unsigned char sign,unsigned char padded){
 int quotient=number;do{quotient/=10;}while(quotient);char text[64],format[8];__clear(text,64);if(padded){__clear(format,8);sprintf(format,TextCanvas_FormatAndRenderSignedPaddedInteger_Format0Dd,(unsigned)width);sprintf(text,format,number);}else if(sign&&number>0)sprintf(text,TextCanvas_FormatAndRenderSignedPaddedInteger_FormatD,number);else sprintf(text,TextCanvasFormatAndRenderSignedPaddedInteger_UnknownRoleInitializedBytes,number);
 unsigned font=TextLookup_SelectFontTableForFont(a);if(right)x=(short)(x-TextLayout_ComputeWidthWithGlyphSpacing(text,font));TextCanvas_RenderStyledTextAndMeasure(p,x,y,text,a,b,c,d,font);
}
