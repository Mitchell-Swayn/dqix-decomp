#include <globaldefs.h>
ARM
extern "C" unsigned char data_02109d94[];extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
// Original: arm9/main @ 0x020A14FC; symbol: func_020a14fc; size: 0x6C.
extern "C" void AllocateTwelveByteEntriesAndPackedBitset(unsigned char* p,void* required,int count){if(!required||!count)return;*(void**)p=_ZN13SafeAllocator8AllocateEj(*(void**)(data_02109d94+8),count*12);*(short*)(p+4)=count;*(short*)(p+6)=0;int bytes=(*(unsigned short*)(p+4)-1)/8+1;*(void**)(p+12)=_ZN13SafeAllocator8AllocateEj(*(void**)(data_02109d94+8),bytes);}
