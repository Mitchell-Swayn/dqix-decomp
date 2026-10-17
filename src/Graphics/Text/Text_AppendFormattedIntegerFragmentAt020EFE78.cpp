#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char data_020efe78[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x02041A28; symbol: func_02041a28; size: 0x34.
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char* p,int n){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,data_020efe78,n);return end+added-p;}
