#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
struct Sizes { unsigned values[4]; };
// Original data: arm9/ov023 @ 0x21fd850; symbol: data_ov023_021fd850.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 002000000048000000040000000800006300.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Sizes MemoryInitializeFourNestedAllocatorsAndBuffers_UnknownRoleInitializedBytes;
struct Owner { SafeAllocator *allocators; char pad[0x420]; void *block54; void *blockA0; void *block8; };
// Original: arm9/ov023 @ 0x021EB080; symbol: func_ov023_021eb080; size: 0xB8.
extern "C" void Memory_InitializeFourNestedAllocatorsAndBuffers(Owner *self, SafeAllocator *allocator) {
    if (allocator) {
        Sizes sizes = MemoryInitializeFourNestedAllocatorsAndBuffers_UnknownRoleInitializedBytes;
        self->allocators = (SafeAllocator *)allocator->Allocate(0x50);
        for (int i = 0; i < 4; ++i) {
            SafeAllocator *array = self->allocators;
            array[i].ResetAllocatorPointer();
            unsigned size = sizes.values[i];
            void *memory = allocator->Allocate(size);
            array[i].CreateTypeA(memory,size);
        }
        self->block54 = allocator->Allocate(0x54);
        self->blockA0 = allocator->Allocate(0xa0);
        self->block8 = allocator->Allocate(8);
    }
}
