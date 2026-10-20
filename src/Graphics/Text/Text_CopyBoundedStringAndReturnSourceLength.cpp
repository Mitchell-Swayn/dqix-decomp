#include <globaldefs.h>
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
// Original: arm9/main @ 0x020D2F28; symbol: func_020d2f28; size: 0x60.
 extern "C" unsigned Text_CopyBoundedStringAndReturnSourceLength(signed char* dst,const signed char* src,int length) { int i=0; const signed char* p=src; if(length-1>0) do { dst[i]=*p; if(!*p)break; ++i; ++p; }while(i<length-1); if(i>=length-1 && length)dst[i]=0; return String_CountBytesUntilTerminator(src); }
