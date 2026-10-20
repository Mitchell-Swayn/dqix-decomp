#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char TextMarkup_AppendXPositionTag_FormatXD[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x02041A28; symbol: func_02041a28; size: 0x34.
extern "C" int TextMarkup_AppendXPositionTag(char* p,int n){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,TextMarkup_AppendXPositionTag_FormatXD,n);return end+added-p;}
