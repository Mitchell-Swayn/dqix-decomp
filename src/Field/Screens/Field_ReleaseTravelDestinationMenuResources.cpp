#include <globaldefs.h>
ARM
extern "C" unsigned int DisplayContext_GetGlobalInstance();
extern "C" void DisplayContext_IgnoreRequestToken(unsigned int, unsigned int);
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(unsigned int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" void* GameResources_GetInstance();
extern "C" void GameResources_ClearSecondaryFlags(int, unsigned int);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3;
struct Obj { unsigned char pad[0x24]; unsigned int display; unsigned char pad2[0x23c]; };
// Original: arm9/ov017 @ 0x021A92A0; symbol: Object_CancelBackgroundLoadAndReleaseResources; size: 0x74.
// Cancels the background request identified by the global display context, releases and frees the allocator at self+0x264 when present, clears a resource flag, and updates display control.
extern "C" void Field_ReleaseTravelDestinationMenuResources(Obj* self) {
    unsigned int context = DisplayContext_GetGlobalInstance();
    DisplayContext_IgnoreRequestToken(context, 0x205);
    BackgroundLoader_CancelEightTasksAndResetState(context);
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)self + 0x264);
    if (allocator) {
        _ZN13SafeAllocator7DestroyEv((char*)self + 0x264);
        Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
    }
    GameResources_ClearSecondaryFlags((int)GameResources_GetInstance(), 0x40);
    volatile unsigned int* display = (volatile unsigned int*)0x04000000;
    *display = (*display & ~0x1f00u) | (self->display << 8);
}
