#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char data_020efeb3[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x02041B70; symbol: func_02041b70; size: 0x3C.
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char* p,int n,const char* text){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,data_020efeb3,n,text);return end+added-p;}
