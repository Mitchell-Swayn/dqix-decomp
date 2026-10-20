#include <globaldefs.h>
ARM
extern "C" void *Object_GetGlobalSixteenEntryDisplayState(void);
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int *, int);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int Main_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable(void);
// Original: arm9/ov017 @ 0x021AC2A8; symbol: func_ov017_021ac2a8; size: 0x44.
extern "C" void FieldEscape_ReleaseExitEffectResources(void *owner) {
    RemoveMatchingNodeAndResetMatchingObjectSlots((int *)Object_GetGlobalSixteenEntryDisplayState(), 5);
    void *allocator = (char *)owner + 0x10;
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    }
    FileCache_RestoreRomTablesIfSpaceAvailable();
}
