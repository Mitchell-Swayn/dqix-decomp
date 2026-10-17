#include <globaldefs.h>
ARM
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" unsigned int data_02114e20;
// Original: arm9/ov017 @ 0x021AEEA8; symbol: func_ov017_021aeea8; size: 0x34.
extern "C" void Memory_DestroyAndFreeSafeAllocatorAt2C(void* p) {
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)p + 0x2c);
    if (allocator) {
        _ZN13SafeAllocator7DestroyEv((char*)p + 0x2c);
        Memory_FreeThroughAllocatorUnion(&data_02114e20, allocator);
    }
}
