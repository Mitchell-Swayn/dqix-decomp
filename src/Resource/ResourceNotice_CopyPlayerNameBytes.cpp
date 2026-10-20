#include <globaldefs.h>
ARM
extern "C" unsigned int strlen(const char*); extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x020D9DC4; symbol: func_020d9dc4; size: 0x28.
 extern "C" void ResourceNotice_CopyPlayerNameBytes(unsigned char* p,const char* text) { unsigned int len=strlen(text);memcpy(p+0x10,text,len); }
