#include <globaldefs.h>
ARM
extern "C" void ResetResourceWithModeZero(void *);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" char data_02114e20[];
// Original: arm9/ov017 @ 0x021C0364; symbol: func_ov017_021c0364; size: 0x40.
extern "C" void ReleaseResourceAndAllocator(void *self) {
    if (*(void **)((unsigned char *)self + 0x1c) != 0)
        ResetResourceWithModeZero(*(void **)((unsigned char *)self + 0x1c));
    void *allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((unsigned char *)self + 8);
    _ZN13SafeAllocator7DestroyEv((unsigned char *)self + 8);
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocator);
}
