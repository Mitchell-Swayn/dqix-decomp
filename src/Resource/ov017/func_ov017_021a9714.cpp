#include <globaldefs.h>
ARM
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" void *GameResources_GetInstance();
extern "C" void ClearWordAtOffset4MaskedBits(int, unsigned int);
extern "C" unsigned char data_02114e20[];
// Original: arm9/ov017 @ 0x021A9714; symbol: func_ov017_021a9714; size: 0x54.
extern "C" void func_ov017_021a9714(void *p) {
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv((char *)p + 0xc);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv((char *)p + 0xc);
        Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
    }
    _ZN13SafeAllocator21ResetAllocatorPointerEv((char *)p + 0xc);
    *((unsigned char *)p + 8) = 0;
    *(unsigned int *)((char *)p + 0x20) = 0;
    ClearWordAtOffset4MaskedBits((int)GameResources_GetInstance(), 0xc0);
}
