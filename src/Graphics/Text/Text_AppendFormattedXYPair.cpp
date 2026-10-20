#include <globaldefs.h>
ARM
extern "C" {int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void func_0200f374(void*,unsigned);void TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);}
#pragma force_active on
extern "C" char Text_AppendFormattedXYPair_FormatXYDD[];
// Original: arm9/main @ 0x02041A90; symbol: func_02041a90; size: 0x3C.
extern "C" int Text_AppendFormattedXYPair(char* p,int a0,int a1){char* out=p+String_CountBytesUntilTerminator(p);int count=sprintf(out,Text_AppendFormattedXYPair_FormatXYDD,a0,a1);return out+count-p;}
