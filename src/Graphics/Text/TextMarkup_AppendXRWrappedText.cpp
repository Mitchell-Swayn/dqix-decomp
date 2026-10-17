#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" char data_020efffc[];extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x0204201C; symbol: func_0204201c; size: 0x3C.
extern "C" int TextMarkup_AppendXRWrappedText(char* p,const char* text,int n){char* end=p+String_CountBytesUntilTerminator(p);int added=sprintf(end,data_020efffc,n,text);return end+added-p;}
