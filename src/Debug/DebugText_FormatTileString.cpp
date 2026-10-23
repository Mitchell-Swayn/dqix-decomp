#include <globaldefs.h>
typedef char* va_list;
#define va_start(ap,last) ((ap)=(char*)(((unsigned)&last & ~3u)+4))
#define va_end(ap) ((void)0)
extern "C" int Runtime_FormatIntoBoundedString(char*,unsigned,const char*,va_list);
extern "C" void DebugText_WriteTileString(int,int,unsigned,const char*);
// Original: arm9/main @ 0x0202AD98; symbol: func_0202ad98; size: 0x58.
extern "C" void DebugText_FormatTileString(unsigned a,unsigned b,unsigned c,const char* format,...) {char text[33];va_list args;va_start(args,format);Runtime_FormatIntoBoundedString(text,33,format,args);DebugText_WriteTileString(a,b,c,text);va_end(args);}
