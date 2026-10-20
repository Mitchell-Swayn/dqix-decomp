#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);}
// Original: arm9/ov003 @ 0x0215F8CC; symbol: Memory_InitializeEightPresentationAllocators; size: 0xf4.
// Allocates eight fixed-sized presentation arenas from an optional parent allocator.
extern "C" void Memory_InitializeEightPresentationAllocators(unsigned char* self,void* heap){if(!heap)return;_ZN13SafeAllocator11CreateTypeAEPvj(self+552,_ZN13SafeAllocator8AllocateEj(heap,4096),4096);_ZN13SafeAllocator11CreateTypeAEPvj(self+572,_ZN13SafeAllocator8AllocateEj(heap,28672),28672);_ZN13SafeAllocator11CreateTypeAEPvj(self+612,_ZN13SafeAllocator8AllocateEj(heap,8192),8192);_ZN13SafeAllocator11CreateTypeAEPvj(self+632,_ZN13SafeAllocator8AllocateEj(heap,29696),29696);_ZN13SafeAllocator11CreateTypeAEPvj(self+652,_ZN13SafeAllocator8AllocateEj(heap,19456),19456);_ZN13SafeAllocator11CreateTypeAEPvj(self+672,_ZN13SafeAllocator8AllocateEj(heap,3072),3072);_ZN13SafeAllocator11CreateTypeAEPvj(self+692,_ZN13SafeAllocator8AllocateEj(heap,15360),15360);_ZN13SafeAllocator11CreateTypeAEPvj(self+712,_ZN13SafeAllocator8AllocateEj(heap,512),512);}
