#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);

// Original: arm9/ov003 @ 0x0215E85C; symbol: func_ov003_0215e85c; size: 0x3C.
extern "C" void Resource_InitializeLinkedCoordinateAndHalfwordEntry(void* self, unsigned allocator, int count) {
    if (allocator == 0 || count < 0) return;
    *(char**)((char*)self + 8) = _ZN13SafeAllocator8AllocateEj(allocator, (unsigned)count << 3);
    *(unsigned short*)((char*)self + 0xC) = (unsigned short)count;
    *(unsigned short*)((char*)self + 0xE) = 0;
}
