#include <globaldefs.h>
ARM
extern "C" {int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void func_0200f374(void*,unsigned);void TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);}
#pragma force_active on
extern "C" char Text_AppendFormattedThreeIntegerFragment_FormatDBDDD[];
// Original: arm9/main @ 0x02041F24; symbol: func_02041f24; size: 0x4C.
extern "C" int Text_AppendFormattedThreeIntegerFragment(char* p,int a0,int a1,int a2){char* out=p+String_CountBytesUntilTerminator(p);int count=sprintf(out,Text_AppendFormattedThreeIntegerFragment_FormatDBDDD,a0,a1,a2);return out+count-p;}
