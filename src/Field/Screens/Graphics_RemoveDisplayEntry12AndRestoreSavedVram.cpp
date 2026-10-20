#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalSixteenEntryDisplayState(void);
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int*, int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(const unsigned*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(const void*);
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable(void);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021A6B30; symbol: Graphics_RemoveDisplayEntry12AndRestoreSavedVram; size: 0x54.
// Removes display-state key 12, destroys and frees a signed allocator allocation when present, restores saved texture image and palette VRAM states, and runs the trailing cleanup.
extern "C" void Graphics_RemoveDisplayEntry12AndRestoreSavedVram(void* self) {
    RemoveMatchingNodeAndResetMatchingObjectSlots((int*)Object_GetGlobalSixteenEntryDisplayState(), 12);
    void* allocator = (char*)self + 0x10;
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    }
    _Z28RestoreTextureImageVRAMStatePKj((unsigned*)((char*)self + 0x24));
    _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState((char*)self + 0x4C);
    FileCache_RestoreRomTablesIfSpaceAvailable();
}
