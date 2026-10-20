#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned int TextContext_GetSharedInstance();
// Original: arm9/ov008 @ 0x021842A0; symbol: func_ov008_021842a0; size: 0x158.
extern "C" void Memory_InitializeNestedAllocatorPools(char* p,unsigned allocator) {
 if(!allocator) return;
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x14,_ZN13SafeAllocator8AllocateEj(allocator,0x2400),0x2400);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x28,_ZN13SafeAllocator8AllocateEj(allocator,0x800),0x800);
 if(!*(int*)(p+0xb24)) {
 _ZN13SafeAllocator11CreateTypeAEPvj(p,_ZN13SafeAllocator8AllocateEj(allocator,0x1000),0x1000);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x3c,_ZN13SafeAllocator8AllocateEj(allocator,0x200),0x200);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x50,_ZN13SafeAllocator8AllocateEj(allocator,0x400),0x400);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x64,_ZN13SafeAllocator8AllocateEj(allocator,0x8800),0x8800);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x78,_ZN13SafeAllocator8AllocateEj(allocator,0x8000),0x8000);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x8c,_ZN13SafeAllocator8AllocateEj(allocator,0x8000),0x8000);
 *(char**)(p+0x730)=_ZN13SafeAllocator8AllocateEj(allocator,0x54);
 *(char**)(p+0x734)=_ZN13SafeAllocator8AllocateEj(allocator,0x2d0);
 *(char**)(p+0x738)=_ZN13SafeAllocator8AllocateEj(allocator,8);
 *(unsigned*)(p+0xb8)=*(unsigned*)(TextContext_GetSharedInstance()+0x5c);
 } else {
 *(char**)(p+0xb8)=_ZN13SafeAllocator8AllocateEj(allocator,0x960);
 }
 *(char**)(p+0x72c)=_ZN13SafeAllocator8AllocateEj((unsigned)(p+0x14),0x1c00);
}
