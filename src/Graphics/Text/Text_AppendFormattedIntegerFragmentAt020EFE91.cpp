#include <globaldefs.h>
ARM
extern "C" {int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void func_0200f374(void*,unsigned);void TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);}
#pragma force_active on
extern "C" char data_020efe91[];
// Original: arm9/main @ 0x02041ACC; symbol: func_02041acc; size: 0x34.
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE91(char* p,int a0){char* out=p+String_CountBytesUntilTerminator(p);int count=sprintf(out,data_020efe91,a0);return out+count-p;}
