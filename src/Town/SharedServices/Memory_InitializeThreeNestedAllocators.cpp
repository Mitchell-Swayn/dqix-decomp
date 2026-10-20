#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" unsigned Resource_ResetZoneAndAllocator();
// Original: arm9/ov003 @ 0x0217BD38; symbol: func_ov003_0217bd38; size: 0x7C.
extern "C" void Memory_InitializeThreeNestedAllocators(char* self) {
*(unsigned*)self=Resource_ResetZoneAndAllocator();
void* p=_ZN13SafeAllocator8AllocateEj(*(unsigned*)self,0x32000);
_ZN13SafeAllocator11CreateTypeAEPvj(self+4,p,0x32000);
_ZN13SafeAllocator5ResetEv(self+4);
p=_ZN13SafeAllocator8AllocateEj(*(unsigned*)self,0x6800);
_ZN13SafeAllocator11CreateTypeAEPvj(self+0x18,p,0x6800);
_ZN13SafeAllocator5ResetEv(self+0x18);
p=_ZN13SafeAllocator8AllocateEj(*(unsigned*)self,0x6800);
_ZN13SafeAllocator11CreateTypeAEPvj(self+0x2c,p,0x6800);
_ZN13SafeAllocator5ResetEv(self+0x2c);
}
