#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
// Original: arm9/ov005 @ 0x02153954; symbol: func_ov005_02153954; size: 0x1CC.
extern "C" void Memory_CreateNestedAllocatorGroup(char* p,unsigned primary,unsigned secondary) {
 if(!primary || !secondary) return;
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x14,_ZN13SafeAllocator8AllocateEj(secondary,0x1300),0x1300);
 for(int i=0;i<8;i++) _ZN13SafeAllocator11CreateTypeAEPvj(p+0x28+i*0x14,_ZN13SafeAllocator8AllocateEj(secondary,0xe0),0xe0);
 for(int i=0;i<16;i++) _ZN13SafeAllocator11CreateTypeAEPvj(p+0xc8+i*0x14,_ZN13SafeAllocator8AllocateEj(secondary,0xe0),0xe0);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x208,_ZN13SafeAllocator8AllocateEj(secondary,0xe0),0xe0);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x21c,_ZN13SafeAllocator8AllocateEj(secondary,0xc00),0xc00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x244,_ZN13SafeAllocator8AllocateEj(primary,0x1e00),0x1e00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p,_ZN13SafeAllocator8AllocateEj(primary,0x4b00),0x4b00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x258,_ZN13SafeAllocator8AllocateEj(primary,0x4a00),0x4a00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x26c,_ZN13SafeAllocator8AllocateEj(primary,0x1e00),0x1e00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x280,_ZN13SafeAllocator8AllocateEj(secondary,0x200),0x200);
 *(char**)(p+0x3d88)=_ZN13SafeAllocator8AllocateEj(primary,0x800);
 *(char**)(p+0x3d8c)=_ZN13SafeAllocator8AllocateEj(secondary,0x200);
 *(char**)(p+0x3d90)=_ZN13SafeAllocator8AllocateEj(primary,0x800);
 *(char**)(p+0x3d94)=_ZN13SafeAllocator8AllocateEj(secondary,0x200);
}
