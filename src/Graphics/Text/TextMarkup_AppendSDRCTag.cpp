#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char data_020efec0[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x02041BAC; symbol: func_02041bac; size: 0x5C.
extern "C" int TextMarkup_AppendSDRCTag(char* p,int n0,int n1,int n2,int n3,int n4){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,data_020efec0,n0,n1,n2,n3,n4);return end+added-p;}
