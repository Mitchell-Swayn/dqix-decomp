#include <globaldefs.h>
ARM
extern "C" unsigned int DisplayContext_GetGlobalInstance(void);
extern "C" void DisplayContext_IgnoreRequestToken(unsigned int, unsigned int);
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
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
// Original: arm9/ov017 @ 0x021A79F0; symbol: func_ov017_021a79f0; size: 0x6C.
extern "C" void Field_ReleaseTravelConfirmationResources(void *owner) {
    unsigned int context = DisplayContext_GetGlobalInstance();
    DisplayContext_IgnoreRequestToken(context, 0x205);
    BackgroundLoader_CancelEightTasksAndResetState(context);
    void *allocator = (char *)owner + 0x25c;
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    }
    FileCache_RestoreRomTablesIfSpaceAvailable();
    volatile unsigned int *display = (volatile unsigned int *)0x04000000;
    *display = (*display & ~0x1f00) | (*(unsigned int *)((char *)owner + 0x1c) << 8);
}
