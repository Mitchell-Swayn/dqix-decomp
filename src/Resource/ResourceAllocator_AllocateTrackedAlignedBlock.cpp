#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char* _ZN13HMRFAllocator8AllocateEji(void*,unsigned,int);extern "C" void* _ZN19SignedAllocatorList13ElementBeforeEP21SignedAllocatorHeader(void*,void*);extern "C" void _ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(void*,void*);
// Original: arm9/main @ 0x020BDA58; symbol: func_020bda58; size: 0x68.
extern "C" void* ResourceAllocator_AllocateTrackedAlignedBlock(unsigned char* p,unsigned size,unsigned a,unsigned b,unsigned c){unsigned char* item=_ZN13HMRFAllocator8AllocateEji(*(void**)p,((size+31)&~31U)+32,32);if(!item)return 0;void* list=_ZN19SignedAllocatorList13ElementBeforeEP21SignedAllocatorHeader(p+4,0);*(unsigned*)(item+8)=size;*(unsigned*)(item+12)=a;*(unsigned*)(item+16)=b;*(unsigned*)(item+20)=c;_ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(list,item);return item+32;}
