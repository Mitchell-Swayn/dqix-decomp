#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char data_020eff1b[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x02041CF4; symbol: func_02041cf4; size: 0x54.
extern "C" int AppendFourFormattedArguments(char* p,int n0,int n1,int n2,int n3){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,data_020eff1b,n0,n1,n2,n3);return end+added-p;}
