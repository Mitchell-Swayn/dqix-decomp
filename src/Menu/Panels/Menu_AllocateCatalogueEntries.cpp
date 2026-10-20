#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void Menu_ResetCatalogueEntry(void*);
struct AllocatedRecordArray { unsigned char pad[4]; void* entries; unsigned short initialized; short count; };
// Original: arm9/ov023 @ 0x021E13B0; symbol: func_ov023_021e13b0; size: 0x60.
extern "C" void Menu_AllocateCatalogueEntries(AllocatedRecordArray* array, unsigned allocator, int count) {
    if (allocator == 0 || count == 0) return;
    array->entries = _ZN13SafeAllocator8AllocateEj(allocator, count << 4);
    array->initialized = 0;
    array->count = count;
    for (short i = 0; i < array->count; ++i)
        Menu_ResetCatalogueEntry((char*)array->entries + i * 16);
}
