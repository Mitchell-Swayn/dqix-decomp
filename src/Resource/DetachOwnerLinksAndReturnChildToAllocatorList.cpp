#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,void*);extern "C" void _ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(void*,void*);extern "C" unsigned char data_0210f3d8[];extern "C" unsigned char data_0210f3cc[];
// Original: arm9/main @ 0x020BC79C; symbol: func_020bc79c; size: 0x84.
extern "C" void DetachOwnerLinksAndReturnChildToAllocatorList(unsigned char* p){void** link=*(void***)p;if(link){*link=0;*(void**)p=0;}unsigned char* list=*(unsigned char**)(p+4);_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(list,p);*(void**)(p+4)=0;void* child=*(void**)(p+8);if(child){_ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(list+12,child);(*(void***)(p+8))[3]=0;*(void**)(p+8)=0;}_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(data_0210f3d8,p);_ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(data_0210f3cc,p);p[44]=0;}
