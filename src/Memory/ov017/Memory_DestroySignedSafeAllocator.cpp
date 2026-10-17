#include <globaldefs.h>
ARM
extern "C" void PopGlobalStackAndOptionallyNotify(int enabled);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void* allocator, void* allocation);
extern "C" unsigned char data_02114e20[];
// Original: arm9/ov017 @ 0x021C07D0; symbol: func_ov017_021c07d0; size: 0x50.
extern "C" void Memory_DestroySignedSafeAllocator(void* self) {
    if (*(int*)((char*)self + 0x1C) != 0) {
        PopGlobalStackAndOptionallyNotify(1);
        *(int*)((char*)self + 0x1C) = 0;
    }
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)self + 8);
    if (allocator == 0) return;
    _ZN13SafeAllocator7DestroyEv((char*)self + 8);
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocator);
}
