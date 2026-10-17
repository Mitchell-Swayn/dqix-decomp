#include <globaldefs.h>
struct Header{char pad[0x3d];unsigned char rank;};extern "C" Header* _ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader(void*,Header*);extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,Header*);extern "C" void ResourceEntry_StopHandleAndRelease(Header*);extern "C" void InsertAllocatorNodeOrderedByByteField3D(Header*);extern "C" char data_0210f3cc[],data_0210f3d8[];
#pragma optimization_level 4
// Original: arm9/main @ 0x020BC734; symbol: func_020bc734; size: 0x68.
extern "C" ARM Header* AcquireFreeOrLowerRankedAllocatorEntry(int rank){Header* p=_ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader(data_0210f3cc,0);if(!p){p=_ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader(data_0210f3d8,0);if(rank<p->rank)return 0;ResourceEntry_StopHandleAndRelease(p);}_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(data_0210f3cc,p);p->rank=rank;InsertAllocatorNodeOrderedByByteField3D(p);return p;}
