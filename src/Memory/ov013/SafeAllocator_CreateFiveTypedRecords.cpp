#include <globaldefs.h>
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned allocator, unsigned size);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*, void*, unsigned);
extern "C" unsigned data_ov013_02187dd8[];
// Original: arm9/ov013 @ 0x02186E74; symbol: func_ov013_02186e74; size: 0x78.
extern "C" void SafeAllocator_CreateFiveTypedRecords(void** output, unsigned allocator) {
    if (!allocator) return;
    *output = _ZN13SafeAllocator8AllocateEj(allocator, 0x64);
    for (unsigned char i = 0; i < 5; ++i) {
        char* block = *(char**)output;
        unsigned offset = (unsigned)i * 0x14;
        _ZN13SafeAllocator21ResetAllocatorPointerEv(block + offset);
        unsigned size = data_ov013_02187dd8[i];
        char* memory = _ZN13SafeAllocator8AllocateEj(allocator, size);
        _ZN13SafeAllocator11CreateTypeAEPvj(block + offset, memory, size);
    }
}
