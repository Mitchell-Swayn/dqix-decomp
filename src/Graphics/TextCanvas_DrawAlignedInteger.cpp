#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f0518; symbol: data_020f0518.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25640000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextCanvasDrawAlignedInteger_UnknownRoleInitializedBytes[];extern "C" int _s32_div_f(int,int);extern "C" int Text_FormatAbsoluteIntegerAndMeasureWidth(unsigned char,int);extern "C" void __clear(void*,unsigned);extern "C" int sprintf(char*,const char*,...);extern "C" void TextCanvas_DrawStringAndMeasureAdvance(void*,int,int,const char*,unsigned char,unsigned char);
// Original: arm9/main @ 0x0205B674; symbol: func_0205b674; size: 0xC0.
extern "C" void TextCanvas_DrawAlignedInteger(unsigned* p,int x,int y,int value,unsigned char a,unsigned char width,unsigned char align,unsigned char mode){char text[12];if(!p[0]||!p[1])return;int n=value;do{n=_s32_div_f(n,10);}while(n);int size=Text_FormatAbsoluteIntegerAndMeasureWidth(mode,value);if(align==1)x=(short)(x+(short)(width*8-size));__clear(text,10);sprintf(text,TextCanvasDrawAlignedInteger_UnknownRoleInitializedBytes,value);TextCanvas_DrawStringAndMeasureAdvance(p,x,y,text,a,mode);}
