#include <globaldefs.h>
#include <std_library_functions.h>
// Original data: arm9/main @ 0x20f0046; symbol: data_020f0046.
// Source-defined character literal. Text: "%d". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "%d".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char TextFormatAbsoluteIntegerAndMeasureWidth_TextD[];
extern "C" void __clear(void*,unsigned);
extern "C" void TextLayout_ComputeWidthWithGlyphSpacing(char*,unsigned);
// Original: arm9/main @ 0x02042658; symbol: func_02042658; size: 0x4C.
extern "C" void Text_FormatAbsoluteIntegerAndMeasureWidth(unsigned a,int value) {char buffer[32];__clear(buffer,32);if(value<0)value=-value;sprintf(buffer,TextFormatAbsoluteIntegerAndMeasureWidth_TextD,value);TextLayout_ComputeWidthWithGlyphSpacing(buffer,a);}
