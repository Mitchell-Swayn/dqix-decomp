#include <globaldefs.h>
ARM
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" unsigned char data_02114e20[];
// Original: arm9/ov017 @ 0x021BA94C; symbol: func_ov017_021ba94c; size: 0x4C.
extern "C" void func_ov017_021ba94c(void *p) {
    if (*(unsigned int *)((char *)p + 0x1c) != 0) {
        OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);
        *(unsigned int *)((char *)p + 0x1c) = 0;
    }
    void *allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char *)p + 8);
    _ZN13SafeAllocator7DestroyEv((char *)p + 8);
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocator);
}
