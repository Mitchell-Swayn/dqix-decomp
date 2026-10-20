#include <globaldefs.h>
ARM
typedef char* va_list;
#define va_start(ap,last) (ap=(char*)(((unsigned)&last & ~3u)+4))
#define va_end(ap) ((void)0)
extern "C" void Runtime_FormatUnboundedVaListString(unsigned,unsigned,va_list);
// Original: arm9/main @ 0x020C7130; symbol: func_020c7130; size: 0x28.
 extern "C" void System_FormatUnboundedString(unsigned a,unsigned b,...){va_list args;va_start(args,b);Runtime_FormatUnboundedVaListString(a,b,args);va_end(args);}
