#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
struct Header { unsigned first; unsigned short a,b,c; unsigned char d,e; };
// Original: arm9/main @ 0x0204A848; symbol: func_0204a848; size: 0xAC.
extern "C" int ParsePackedImageHeaderAndDispatchFlushedData(Header* self,void(*callback)(const void*,unsigned,unsigned),const char* input) { unsigned length,header; memcpy(&header,input,4); memcpy(&self->a,input+4,2); memcpy(&self->b,input+6,2); memcpy(&self->c,input+8,2); memcpy(&self->d,input+10,1); memcpy(&self->e,input+11,1); memcpy(&length,input+12,4); CleanInvalidateCacheRange(input+16,length); callback(input+16,self->first,length); return 0; }
