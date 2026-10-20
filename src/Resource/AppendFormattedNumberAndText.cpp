#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char AppendFormattedNumberAndText_FormatTITLEDSTITLE[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x02041FAC; symbol: func_02041fac; size: 0x3C.
extern "C" int AppendFormattedNumberAndText(char* p,const char* text,int n){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,AppendFormattedNumberAndText_FormatTITLEDSTITLE,n,text);return end+added-p;}
