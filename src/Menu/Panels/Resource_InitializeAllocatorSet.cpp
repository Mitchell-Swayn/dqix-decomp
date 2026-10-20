#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*, void*, unsigned);
// Original: arm9/ov023 @ 0x021E71B4; symbol: func_ov023_021e71b4; size: 0x6C.
extern "C" void Resource_InitializeAllocatorSet(void* object, unsigned allocator) {
    if (allocator == 0) return;
    _ZN13SafeAllocator11CreateTypeAEPvj(object, _ZN13SafeAllocator8AllocateEj(allocator, 0x5000), 0x5000);
    _ZN13SafeAllocator11CreateTypeAEPvj((char*)object + 0x14, _ZN13SafeAllocator8AllocateEj(allocator, 0x3400), 0x3400);
    _ZN13SafeAllocator11CreateTypeAEPvj((char*)object + 0x28, _ZN13SafeAllocator8AllocateEj(allocator, 0x0ccc), 0x0ccc);
}
