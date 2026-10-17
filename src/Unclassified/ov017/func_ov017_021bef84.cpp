#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance();
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" void ClearWordAtOffset4MaskedBits(int, unsigned int);
extern "C" unsigned char data_02114e20[];

// Original: arm9/ov017 @ 0x021BEF84; symbol: func_ov017_021bef84; size: 0x48.
extern "C" void func_ov017_021bef84(void *object) {
    void *resources = GameResources_GetInstance();
    void *allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((unsigned char *)object + 0x44);
    if (allocator != 0) {
        _ZN13SafeAllocator7DestroyEv((unsigned char *)object + 0x44);
        Memory_FreeThroughAllocatorUnion(data_02114e20, allocator);
    }
    ClearWordAtOffset4MaskedBits((int)resources, 0xc0);
}
