#include <globaldefs.h>
ARM
extern "C" void ClearWordHalfwordsAndByteAt0A(void*);extern "C" void ClearHalfwordPairBytePairAndWordPair(void*);
// Original: arm9/main @ 0x0204AFB4; symbol: func_0204afb4; size: 0x5C.
extern "C" void ResetRecordAndIndexedEntries(unsigned char* p){*(int*)(p+20)=0;ClearWordHalfwordsAndByteAt0A(p);p[12]=0;*(unsigned short*)(p+14)=65535;if(!*(void**)(p+16))return;for(unsigned char i=0;i<p[29];++i)ClearHalfwordPairBytePairAndWordPair(*(unsigned char**)(p+16)+i*16);}
