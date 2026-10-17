#include <globaldefs.h>
ARM
extern "C" {int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void func_0200f374(void*,unsigned);void TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);}
#pragma force_active on
extern "C" char data_020efee4[];
// Original: arm9/main @ 0x02041C08; symbol: func_02041c08; size: 0x5C.
extern "C" int AppendFiveFormattedArguments(char* p,int a0,int a1,int a2,int a3,int a4){char* out=p+String_CountBytesUntilTerminator(p);int count=sprintf(out,data_020efee4,a0,a1,a2,a3,a4);return out+count-p;}
