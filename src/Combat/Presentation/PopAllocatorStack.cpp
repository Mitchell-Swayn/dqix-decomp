#include <globaldefs.h>
ARM
extern "C" void Combat_ProcessDeferredPresentationCleanup(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void _ZN13SafeAllocator4FreeEPv(void*, void*);
extern "C" void TextureVRAM_SnapshotAllocationBounds(char*);
struct AllocatorStack { unsigned char data[0x30]; volatile unsigned char count; };
// Original: arm9/ov025 @ 0x021E8AF8; symbol: func_ov025_021e8af8; size: 0x74.
extern "C" void PopAllocatorStack(AllocatorStack* stack) {
    unsigned count = stack->count;
    if (count == 0) return;
    Combat_ProcessDeferredPresentationCleanup(stack);
    void* allocator = *(void**)((char*)stack + stack->count * 4 + 0x10);
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    _ZN13SafeAllocator7DestroyEv(*(void**)((char*)stack + stack->count * 4 + 0x10));
    _ZN13SafeAllocator4FreeEPv(*(void**)((char*)stack + (stack->count - 1) * 4 + 0x10), allocation);
    TextureVRAM_SnapshotAllocationBounds(*(char**)((char*)stack + stack->count * 4 + 0x20));
    stack->count = stack->count - 1;
}
