#include <globaldefs.h>
ARM
extern "C" {int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void func_0200f374(void*,unsigned);void TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);}
#pragma force_active on
extern "C" char data_020effcb[];
// Original: arm9/main @ 0x02041F70; symbol: func_02041f70; size: 0x3C.
extern "C" int TextMarkup_AppendTenTag(char* p,int a0,int a1){char* out=p+String_CountBytesUntilTerminator(p);int count=sprintf(out,data_020effcb,a0,a1);return out+count-p;}
