#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
struct Sizes { unsigned values[3]; };
struct Allocator { char data[20]; };
struct Pool { void* buffer; Allocator* allocators; };
extern "C" Sizes data_ov003_0217f4e4;
// Original: arm9/ov003 @ 0x0216724C; symbol: func_ov003_0216724c; size: 0x98.
extern "C" void Memory_AllocateThreeSizedPools(Pool* self,unsigned allocator) {
if(allocator) {
self->allocators=(Allocator*)_ZN13SafeAllocator8AllocateEj(allocator,60);
Sizes sizes=data_ov003_0217f4e4;
for(int i=0;i<3;++i) {
unsigned size=sizes.values[i];
void* block=_ZN13SafeAllocator8AllocateEj(allocator,size);
_ZN13SafeAllocator11CreateTypeAEPvj(&self->allocators[i],block,size);
}
if(!self->buffer) self->buffer=_ZN13SafeAllocator8AllocateEj(allocator,0x4000);
}
}
