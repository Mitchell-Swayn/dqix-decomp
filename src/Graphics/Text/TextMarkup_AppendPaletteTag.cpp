#include <globaldefs.h>
ARM
extern "C" {int String_CountBytesUntilTerminator(const char*);int sprintf(char*,const char*,...);void func_0200f374(void*,unsigned);void TextLayout_ComputeWidthWithGlyphSpacing(const char*,void*);}
#pragma force_active on
// Original data: arm9/main @ 0x20eff74; symbol: data_020eff74.
// Source-defined character literal. Text: "<PLTT=%d>". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "<PLTT=%d>".
// Observed span: 19 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextMarkupAppendPaletteTag_TextPLTTDWithAdjacentText[];
// Original: arm9/main @ 0x02041E70; symbol: func_02041e70; size: 0x34.
extern "C" int TextMarkup_AppendPaletteTag(char* p,int a0){char* out=p+String_CountBytesUntilTerminator(p);int count=sprintf(out,TextMarkupAppendPaletteTag_TextPLTTDWithAdjacentText,a0);return out+count-p;}
