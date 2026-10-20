#include <globaldefs.h>
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned allocator, unsigned size);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*, void*, unsigned);
// Original data: arm9/ov013 @ 0x2187dd8; symbol: data_ov013_02187dd8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000a0000000a0000000c000000040000000800000000000000000000000000000000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" unsigned SafeAllocatorCreateFiveTypedRecords_UnknownRoleInitializedBytes[];
// Original: arm9/ov013 @ 0x02186E74; symbol: func_ov013_02186e74; size: 0x78.
extern "C" void SafeAllocator_CreateFiveTypedRecords(void** output, unsigned allocator) {
    if (!allocator) return;
    *output = _ZN13SafeAllocator8AllocateEj(allocator, 0x64);
    for (unsigned char i = 0; i < 5; ++i) {
        char* block = *(char**)output;
        unsigned offset = (unsigned)i * 0x14;
        _ZN13SafeAllocator21ResetAllocatorPointerEv(block + offset);
        unsigned size = SafeAllocatorCreateFiveTypedRecords_UnknownRoleInitializedBytes[i];
        char* memory = _ZN13SafeAllocator8AllocateEj(allocator, size);
        _ZN13SafeAllocator11CreateTypeAEPvj(block + offset, memory, size);
    }
}
