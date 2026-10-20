#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
// Original: arm9/ov003 @ 0x0215E750; symbol: func_ov003_0215e750; size: 0x40.
extern "C" void Script_CreateLinkedCoordinateHalfwordEntries(void* self, unsigned allocator, int count) {
    if (allocator == 0 || count < 0) return;
    *(char**)self = _ZN13SafeAllocator8AllocateEj(allocator, count * 0x14);
    *(unsigned short*)((char*)self + 4) = (unsigned short)count;
    *(unsigned short*)((char*)self + 6) = 0;
}
