#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char data_020eff11[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x02041CC0; symbol: func_02041cc0; size: 0x34.
extern "C" int TextMarkup_AppendLineTag(char* p,int n){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,data_020eff11,n);return end+added-p;}
