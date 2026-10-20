#include <globaldefs.h>
ARM
extern "C" {int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void func_0200f374(void*,unsigned);void TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);}
#pragma force_active on
extern "C" char TextMarkup_AppendFrameTag_FormatFRAMEDDDDD[];
// Original: arm9/main @ 0x02041C08; symbol: func_02041c08; size: 0x5C.
extern "C" int TextMarkup_AppendFrameTag(char* p,int a0,int a1,int a2,int a3,int a4){char* out=p+String_CountBytesUntilTerminator(p);int count=sprintf(out,TextMarkup_AppendFrameTag_FormatFRAMEDDDDD,a0,a1,a2,a3,a4);return out+count-p;}
