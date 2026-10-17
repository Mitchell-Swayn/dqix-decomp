#include <globaldefs.h>
ARM
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const char*,int);
// Original: arm9/ov009 @ 0x0218A4C8; symbol: func_ov009_0218a4c8; size: 0x50.
extern "C" int func_ov009_0218a4c8(void* unused,const void* pattern,const char* source,int mode,int count) {
 for(int i=0;i<count;i++,source++) if(RuntimeMemory_CompareByteRanges(pattern,source,mode)==0) return 1;
 return 0;
}
