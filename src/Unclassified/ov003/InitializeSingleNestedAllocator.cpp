#include <globaldefs.h>
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" unsigned data_ov003_0217f280[];
// Original: arm9/ov003 @ 0x021536E0; symbol: func_ov003_021536e0; size: 0x8C.
extern "C" ARM void InitializeSingleNestedAllocator(unsigned char** output,void* allocator) { *output=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,20); unsigned sizes[1]; unsigned* sizeTable=sizes; sizes[0]=data_ov003_0217f280[1]; for(unsigned char i=0;i<1;++i) { _ZN13SafeAllocator21ResetAllocatorPointerEv(*output+i*20); unsigned size=sizeTable[i]; void* memory=_ZN13SafeAllocator8AllocateEj(allocator,size); _ZN13SafeAllocator11CreateTypeAEPvj(*output+i*20,memory,size); } }
