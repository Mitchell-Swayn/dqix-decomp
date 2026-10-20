#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
struct Owner {unsigned a,b;SignedAllocatorList lists[24];};
// Original: arm9/main @ 0x02054F80; symbol: func_02054f80; size: 0x100.
extern "C" void InitializeSignedAllocatorLists(Owner* self) {self->a=0;self->b=0;SignedAllocatorList* d;SignedAllocatorList* c;SignedAllocatorList* b;SignedAllocatorList* a;a=self->lists;b=self->lists+3;c=self->lists+6;d=self->lists+10;for(int i=0;i<3;++i) {a[i].Initialize(4);b[i].Initialize(4);c[i].Initialize(4);d[i].Initialize(4);}self->lists[9].Initialize(4);self->lists[13].Initialize(4);self->lists[14].Initialize(4);self->lists[15].Initialize(4);self->lists[16].Initialize(4);self->lists[17].Initialize(4);self->lists[18].Initialize(4);self->lists[19].Initialize(4);self->lists[20].Initialize(4);self->lists[21].Initialize(4);self->lists[22].Initialize(4);self->lists[23].Initialize(4);}
