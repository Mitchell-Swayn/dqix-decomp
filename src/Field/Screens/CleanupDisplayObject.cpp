#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int*, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void SoundSfx_RestoreHeapAfterGroupPlayback(unsigned char*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();
struct DisplayObject { unsigned char pad[0x30]; unsigned char allocator[4]; };
// Original: arm9/ov017 @ 0x021A7280; symbol: func_ov017_021a7280; size: 0x5C.
extern "C" void CleanupDisplayObject(DisplayObject* object) {
    RemoveMatchingNodeAndResetMatchingObjectSlots((int*)Object_GetGlobalSixteenEntryDisplayState(), 0xd);
    GameObject_RequestMovementInputEnable(_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv()));
    SoundSfx_RestoreHeapAfterGroupPlayback(Main_UnknownRoleZeroInitializedStorage);
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)object + 0x30);
    if (allocator != 0) {
        _ZN13SafeAllocator7DestroyEv((char*)object + 0x30);
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
    }
    FileCache_RestoreRomTablesIfSpaceAvailable();
}
