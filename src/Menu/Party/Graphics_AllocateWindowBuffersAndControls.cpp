#include <globaldefs.h>
ARM
extern "C" {
void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void Window_ConfigureCharacterBufferTransfer(unsigned*,unsigned,unsigned,unsigned char);
void Window_ConfigureCharacterBufferDestination(void*,unsigned,unsigned,unsigned char);
void Window_AllocateAndInitializeEntryArraysAndControls(unsigned char*,unsigned,unsigned,unsigned,void*,int,unsigned char);
}
// Original: arm9/ov002 @ 0x02154D40; symbol: func_ov002_02154d40; size: 0x20C.
extern "C" void Graphics_AllocateWindowBuffersAndControls(unsigned char* p,void* allocator) {
 if(!allocator) return;
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x810,_ZN13SafeAllocator8AllocateEj(allocator,0x3c00),0x3c00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x83c,_ZN13SafeAllocator8AllocateEj(allocator,0x5400),0x5400);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x828,_ZN13SafeAllocator8AllocateEj(allocator,0xd400),0xd400);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x850,_ZN13SafeAllocator8AllocateEj(allocator,0x4c00),0x4c00);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x864,_ZN13SafeAllocator8AllocateEj(allocator,0x9400),0x9400);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x878,_ZN13SafeAllocator8AllocateEj(allocator,0x800),0x800);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x88c,_ZN13SafeAllocator8AllocateEj(allocator,0x580),0x580);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x8a0,_ZN13SafeAllocator8AllocateEj(allocator,0x533),0x533);
 *(void**)(p+0x1a64)=_ZN13SafeAllocator8AllocateEj(allocator,0x6b8);
 *(void**)(p+0x1a68)=_ZN13SafeAllocator8AllocateEj(allocator,0x54);
 *(void**)(p+0x1a6c)=_ZN13SafeAllocator8AllocateEj(allocator,8);
 *(void**)(p+0x1bd4)=_ZN13SafeAllocator8AllocateEj(allocator,0x960);
 *(void**)p=_ZN13SafeAllocator8AllocateEj(allocator,0x24);
 *(void**)(p+4)=_ZN13SafeAllocator8AllocateEj(allocator,0x24);
 Window_AllocateAndInitializeEntryArraysAndControls(*(unsigned char**)p,0,0,0,allocator,12,0x40);
 Window_AllocateAndInitializeEntryArraysAndControls(*(unsigned char**)(p+4),0,1,*(unsigned*)(p+0x1a6c),allocator,4,0x60);
 unsigned char* controls=*(unsigned char**)(*(unsigned char**)p+0xc);
 Window_ConfigureCharacterBufferTransfer((unsigned*)(controls+0xc),0,0x3000,5);
 Window_ConfigureCharacterBufferDestination(controls+0xc,0x3800,0x3000,4);
}
