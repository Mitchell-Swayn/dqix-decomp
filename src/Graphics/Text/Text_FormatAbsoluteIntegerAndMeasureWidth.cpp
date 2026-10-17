#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" const char data_020f0046[];
extern "C" void __clear(void*,unsigned);
extern "C" void TextLayout_ComputeWidthWithGlyphSpacing(char*,unsigned);
// Original: arm9/main @ 0x02042658; symbol: func_02042658; size: 0x4C.
extern "C" void Text_FormatAbsoluteIntegerAndMeasureWidth(unsigned a,int value) {char buffer[32];__clear(buffer,32);if(value<0)value=-value;sprintf(buffer,data_020f0046,value);TextLayout_ComputeWidthWithGlyphSpacing(buffer,a);}
