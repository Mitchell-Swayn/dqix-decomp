#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
extern "C" void InitializeFixedPointScalesAndInvalidIndices(void*);
extern "C" void Object_ClearWordAndHalfwordOutput(unsigned*);
// Original: arm9/ov000 @ 0x02172128; symbol: func_ov000_02172128; size: 0x164.
extern "C" void Memory_InitializePoolsAndFortyTransformStates(char* p,unsigned a) {
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x1a78,_ZN13SafeAllocator8AllocateEj(a,0x400),0x400);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x1a8c,_ZN13SafeAllocator8AllocateEj(a,0x1400),0x1400);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x1ab4,_ZN13SafeAllocator8AllocateEj(a,0x2c00),0x3000);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x1aa0,_ZN13SafeAllocator8AllocateEj(a,0x7000),0x7000);
 _ZN13SafeAllocator5ResetEv(p+0x1a8c);
 _ZN13SafeAllocator5ResetEv(p+0x1aa0);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x1ac8,_ZN13SafeAllocator8AllocateEj(a,0x4266),0x4266);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x1adc,_ZN13SafeAllocator8AllocateEj(a,0xc00),0xc00);
 *(char**)(p+0x170)=_ZN13SafeAllocator8AllocateEj(a,0x640);
 for(unsigned char i=0;i<40;i++) InitializeFixedPointScalesAndInvalidIndices(*(char**)(p+0x170)+i*40);
 *(char**)(p+0x174)=_ZN13SafeAllocator8AllocateEj(a,8);
 Object_ClearWordAndHalfwordOutput(*(unsigned**)(p+0x174));
 unsigned remaining=_ZNK13SafeAllocator24GetMaxPossibleAllocationEv((void*)a);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x1af8,_ZN13SafeAllocator8AllocateEj(a,remaining),remaining);
}
