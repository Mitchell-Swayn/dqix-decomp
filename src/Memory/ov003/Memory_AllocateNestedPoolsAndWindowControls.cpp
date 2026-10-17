#include <globaldefs.h>
ARM
struct State;
struct SafeAllocator;
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void InitializeFixedPointScalesAndInvalidIndices(State*);
extern "C" void Object_ClearWordAndHalfwordOutput(unsigned*);
extern "C" void Window_AllocateAndInitializeEntryArraysAndControls(unsigned char*,unsigned,unsigned,unsigned,SafeAllocator*,int,unsigned char);
// Original: arm9/ov003 @ 0x02158A84; symbol: func_ov003_02158a84; size: 0x134.
extern "C" void Memory_AllocateNestedPoolsAndWindowControls(unsigned char* p,unsigned alloc) {
 if(alloc) {
 _ZN13SafeAllocator11CreateTypeAEPvj(p,_ZN13SafeAllocator8AllocateEj(alloc,0x4000),0x4000);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x14,_ZN13SafeAllocator8AllocateEj(alloc,0x7000),0x7000);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x28,_ZN13SafeAllocator8AllocateEj(alloc,0x8000),0x8000);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x3c,_ZN13SafeAllocator8AllocateEj(alloc,0x800),0x800);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x50,_ZN13SafeAllocator8AllocateEj(alloc,0x200),0x200);
 *(char**)(p+0xec)=_ZN13SafeAllocator8AllocateEj(alloc,0x230);
 for(int i=0;i<14;i++) InitializeFixedPointScalesAndInvalidIndices((State*)(*(char**)(p+0xec)+i*0x28));
 *(char**)(p+0xf0)=_ZN13SafeAllocator8AllocateEj(alloc,8);
 Object_ClearWordAndHalfwordOutput(*(unsigned**)(p+0xf0));
 _ZN13SafeAllocator5ResetEv(p+0x50);
 *(char**)(p+0x570)=_ZN13SafeAllocator8AllocateEj((unsigned)(p+0x50),0x24);
 Window_AllocateAndInitializeEntryArraysAndControls(*(unsigned char**)(p+0x570),0,1,*(unsigned*)(p+0xf0),(SafeAllocator*)(p+0x50),4,0x40);
 }
}
