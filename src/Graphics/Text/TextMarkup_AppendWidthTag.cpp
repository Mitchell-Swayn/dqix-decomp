#include <globaldefs.h>
ARM
extern "C" {int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void func_0200f374(void*,unsigned);void TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);}
#pragma force_active on
extern "C" char TextMarkup_AppendWidthTag_FormatWD[];
// Original: arm9/main @ 0x02041ACC; symbol: func_02041acc; size: 0x34.
extern "C" int TextMarkup_AppendWidthTag(char* p,int a0){char* out=p+String_CountBytesUntilTerminator(p);int count=sprintf(out,TextMarkup_AppendWidthTag_FormatWD,a0);return out+count-p;}
