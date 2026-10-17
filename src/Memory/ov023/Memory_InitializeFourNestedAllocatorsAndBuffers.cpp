#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
struct Sizes { unsigned values[4]; };
extern "C" Sizes data_ov023_021fd850;
struct Owner { SafeAllocator *allocators; char pad[0x420]; void *block54; void *blockA0; void *block8; };
// Original: arm9/ov023 @ 0x021EB080; symbol: func_ov023_021eb080; size: 0xB8.
extern "C" void Memory_InitializeFourNestedAllocatorsAndBuffers(Owner *self, SafeAllocator *allocator) {
    if (allocator) {
        Sizes sizes = data_ov023_021fd850;
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
