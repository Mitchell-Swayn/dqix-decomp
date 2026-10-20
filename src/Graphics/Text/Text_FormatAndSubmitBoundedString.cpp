#include <globaldefs.h>
ARM
typedef char* va_list;
#define va_start(ap,last) (ap=(char*)(((unsigned)&last & ~3u)+4))
#define va_end(ap) ((void)0)
extern "C" void Runtime_FormatIntoBoundedString(char*,unsigned,const char*,va_list); extern "C" void Text_SubmitStringAtScreenPosition(unsigned,unsigned,char*);
// Original: arm9/main @ 0x020290E8; symbol: func_020290e8; size: 0x58.
 extern "C" void Text_FormatAndSubmitBoundedString(unsigned a,unsigned b,const char* format,...){char buf[256]; va_list args;va_start(args,format);Runtime_FormatIntoBoundedString(buf,256,format,args);buf[255]=0;Text_SubmitStringAtScreenPosition(a,b,buf);va_end(args);}
