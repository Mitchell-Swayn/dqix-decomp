#include <globaldefs.h>
ARM
extern "C" char* strncpy(char*,const char*,unsigned);
// Original: arm9/main @ 0x020464A4; symbol: func_020464a4; size: 0x38.
extern "C" void Text_CopyBoundedNullTerminatedString(const char* src,char* dst,unsigned n){if(!src||!dst)return;strncpy(dst,src,n-1);dst[n-1]=0;}
