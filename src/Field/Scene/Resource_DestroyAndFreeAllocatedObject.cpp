#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalSixteenEntryDisplayState(void);
extern "C" void SoundSfx_RestoreHeapAfterGroupPlayback(unsigned char* p);
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int* p, int key);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void* self);
extern "C" void _ZN13SafeAllocator7DestroyEv(void* self);
extern "C" void Memory_FreeThroughAllocatorUnion(void* allocator, void* allocation);
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
// Original: arm9/ov017 @ 0x021C310C; symbol: func_ov017_021c310c; size: 0x60.
extern "C" void Resource_DestroyAndFreeAllocatedObject(char* object) {
    if (*(int*)(object + 0x90) != 0) {
        void* display = Object_GetGlobalSixteenEntryDisplayState();
        SoundSfx_RestoreHeapAfterGroupPlayback(Main_UnknownRoleZeroInitializedStorage);
        RemoveMatchingNodeAndResetMatchingObjectSlots((int*)display, 0x11);
    }
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(object + 8);
    if (allocation == 0)
        return;
    _ZN13SafeAllocator7DestroyEv(object + 8);
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
}
