#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
#include <std_library_functions.h>
extern "C" char data_020f2dc8[],data_020f2dcb[],data_020f2dcf[];extern "C" int String_CountBytesUntilTerminator(const char*);extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
// Original: arm9/main @ 0x020E462C; symbol: func_020e462c; size: 0x98.
extern "C" ARM char* AppendDirectoryAndFilePathWithSeparator(char* out,const char* directory,const char* file){if(directory && *directory){out+=sprintf(out,data_020f2dc8,directory);int size;int result;if(directory && (size=String_CountBytesUntilTerminator(directory))>3)result=RuntimeMemory_CompareByteRanges(directory+(size-3),data_020f2dcb,3);else result=1;if(result)out+=sprintf(out,data_020f2dcf);}return out+sprintf(out,file);}
