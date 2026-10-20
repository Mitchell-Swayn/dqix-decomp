#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20efec0; symbol: data_020efec0.
// Source-defined character literal. Text: "<SDRC=%d,%d,%d,%d,%d>". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "<SDRC=%d,%d,%d,%d,%d>".
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextMarkupAppendSDRCTag_TextSDRCDDDDDWithAdjacentText[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x02041BAC; symbol: func_02041bac; size: 0x5C.
extern "C" int TextMarkup_AppendSDRCTag(char* p,int n0,int n1,int n2,int n3,int n4){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,TextMarkupAppendSDRCTag_TextSDRCDDDDDWithAdjacentText,n0,n1,n2,n3,n4);return end+added-p;}
