#include <globaldefs.h>
ARM
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" unsigned char data_02114e20[];
extern "C" void Resource_InitializeTypeSixtyFiveRecord(signed char*);
// Original: arm9/ov017 @ 0x021A7DD8; symbol: func_ov017_021a7dd8; size: 0x3C.
extern "C" void Resource_DestroyAndResetTypeSixtyFiveRecord(void* self) {
    void* allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char*)self + 8);
    if (allocator != 0) {
        _ZN13SafeAllocator7DestroyEv((char*)self + 8);
        Memory_FreeThroughAllocatorUnion(data_02114e20, allocator);
    }
    Resource_InitializeTypeSixtyFiveRecord((signed char*)self);
}
