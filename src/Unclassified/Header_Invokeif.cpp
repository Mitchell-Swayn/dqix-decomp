#include <globaldefs.h>
struct Header{int a,b;void* allocation;Header* parent;unsigned index;};extern "C" void FinalizeOwnerAndRemoveFromAllocatorTree(void*);extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,Header*);extern "C" char data_0210f824[];
#pragma optimization_level 4
// Original: arm9/main @ 0x020BC820; symbol: func_020bc820; size: 0x50.
extern "C" ARM void Header_Invokeif(Header* p){if(!p->allocation)return;FinalizeOwnerAndRemoveFromAllocatorTree(p->allocation);if(p->parent){p->parent->allocation=0;return;}_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(data_0210f824+p->index*36+12,p);}
