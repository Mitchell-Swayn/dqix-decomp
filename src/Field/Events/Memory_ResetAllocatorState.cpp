#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void Memory_DestroySignedSafeAllocator(void *);
// Original: arm9/ov017 @ 0x021C0820; symbol: func_ov017_021c0820; size: 0x30.
extern "C" void Memory_ResetAllocatorState(void *object) {
    Memory_DestroySignedSafeAllocator(object);
    *(int *)((char *)object + 0x20) = 0;
    *(unsigned char *)((char *)object + 0x24) = 0;
    *(int *)((char *)object + 0x1c) = 0;
    _ZN13SafeAllocator21ResetAllocatorPointerEv((char *)object + 8);
    *(unsigned char *)((char *)object + 0xbc) = 0;
}
