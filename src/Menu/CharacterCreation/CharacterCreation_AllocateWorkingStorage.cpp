#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" {
void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void InitializeBufferHeaderAndStatusBytes(void*);
void TextEntry_InitializeControlAndGridTables(void*);
void* memset(void*,int,unsigned);
}
static inline void AllocateArena(void* destination,void* allocator,unsigned size) {
 _ZN13SafeAllocator11CreateTypeAEPvj(destination,_ZN13SafeAllocator8AllocateEj(allocator,size),size);
}
#define P(o) (*(unsigned char**)(self+(o)))
// This original entry point has no static callers; retain its original ROM range.
#pragma force_active on
// Original: arm9/ov009 @ 0x021842A0; symbol: func_ov009_021842a0; size: 0x2AC.
// Allocates character creation arenas, paired name buffers and optional standalone workspaces.
extern "C" void CharacterCreation_AllocateWorkingStorage(unsigned char* self,void* allocator) {
 if(!allocator)return;
 AllocateArena(self,allocator,0x3800);AllocateArena(self+0x14,allocator,0x3400);
 AllocateArena(self+0x28,allocator,0x1000);AllocateArena(self+0x3c,allocator,0x2b240);
 AllocateArena(self+0x50,allocator,0xc00);AllocateArena(self+0x64,allocator,0x2000);
 AllocateArena(self+0x78,allocator,0x400);AllocateArena(self+0x8c,allocator,0x800);AllocateArena(self+0xa0,allocator,0x1800);
 P(0xdb0)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,8);
 for(int i=0;i<2;i++){
 ((void**)P(0xdb0))[i]=_ZN13SafeAllocator8AllocateEj(allocator,0x48);
 memset(((void**)P(0xdb0))[i],0,0x48);
 }
 P(0xc0)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,0x28);
 P(0xc4)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,0x10);
 InitializeBufferHeaderAndStatusBytes(P(0xc0));TextEntry_InitializeControlAndGridTables(P(0xc4));
 P(0x7d8)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,0x54);
 P(0x7dc)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,0xf0);
 P(0x7e0)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,8);
 P(0x7e4)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,0x54);
 P(0x7e8)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,0x3e8);
 P(0x7ec)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,8);
 if(self[0xd95])return;
 P(0xb4)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,0x14);
 P(0xb8)=(unsigned char*)_ZN13SafeAllocator8AllocateEj(allocator,0x28);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(P(0xb4));
 for(int i=0;i<2;i++)_ZN13SafeAllocator21ResetAllocatorPointerEv(P(0xb8)+i*0x14);
 void* first=_ZN13SafeAllocator8AllocateEj(allocator,0xc000);
 _ZN13SafeAllocator11CreateTypeAEPvj(P(0xb4),first,0xc000);
 void* second=_ZN13SafeAllocator8AllocateEj(allocator,0x3000);
 _ZN13SafeAllocator11CreateTypeAEPvj(P(0xb8),second,0x3000);
 void* third=_ZN13SafeAllocator8AllocateEj(allocator,0x1800);
 _ZN13SafeAllocator11CreateTypeAEPvj(P(0xb8)+0x14,third,0x1800);
}

#pragma force_active reset
