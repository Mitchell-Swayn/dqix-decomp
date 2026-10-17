#include <globaldefs.h>
ARM
extern "C" unsigned char data_02114e20[];
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
// Original: arm9/ov017 @ 0x021BAC8C; symbol: func_ov017_021bac8c; size: 0x4C.
extern "C" void Overlay_DestroyAllocatorAndFreeSignedAllocation(void* self) {
    if (*(unsigned*)((char*)self + 0x20) != 0) {
        OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);
        *(unsigned*)((char*)self + 0x20) = 0;
    }
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)self + 0xc);
    _ZN13SafeAllocator7DestroyEv((char*)self + 0xc);
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocator);
}
