#include <globaldefs.h>
ARM
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" unsigned int data_02114e20;
// Original: arm9/ov017 @ 0x021ADB1C; symbol: func_ov017_021adb1c; size: 0x34.
extern "C" void Memory_DestroyAndFreeSafeAllocator(void* p) {
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)p + 8);
    if (allocator) {
        _ZN13SafeAllocator7DestroyEv((char*)p + 8);
        Memory_FreeThroughAllocatorUnion(&data_02114e20, allocator);
    }
}
