#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
extern "C" {
extern SignedAllocatorList data_0210f3d8;
// Original: arm9/main @ 0x020BC0F8; symbol: func_020bc0f8; size: 0x60.
unsigned int CountAllocatorNodesWithKindTwoAndTwoMatchingHalfwords(int a,int b){unsigned int count=0;SignedAllocatorHeader *p=data_0210f3d8.ElementAfter(0);if(p)do{unsigned short *q=(unsigned short *)p;if(q[26]==2&&q[28]==a&&q[29]==b)count++;p=data_0210f3d8.ElementAfter(p);}while(p);return count;}
}
