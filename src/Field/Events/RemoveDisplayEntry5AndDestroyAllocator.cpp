#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int*, int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();
// Original: arm9/ov017 @ 0x021BEB48; symbol: RemoveDisplayEntry5AndDestroyAllocator; size: 0x44.
// Removes global display-list key 5, destroys and frees the object allocator when present, then runs the cleanup helper.
extern "C" void RemoveDisplayEntry5AndDestroyAllocator(unsigned char* self) {
    RemoveMatchingNodeAndResetMatchingObjectSlots((int*)Object_GetGlobalSixteenEntryDisplayState(), 5);
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv(self + 0x24);
    if (allocator) {
        _ZN13SafeAllocator7DestroyEv(self + 0x24);
        Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
    }
    FileCache_RestoreRomTablesIfSpaceAvailable();
}
