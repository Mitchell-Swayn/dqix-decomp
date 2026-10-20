#include <globaldefs.h>
ARM

extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);

// Original: arm9/ov003 @ 0x0217E334; symbol: func_ov003_0217e334; size: 0x38.
extern "C" void InitializeSafeAllocatorObject(unsigned char *object) {
    LinkedQueue_InitializeNodeStatus((signed char *)object);
    object[0] = 0x11;
    *(unsigned int *)(object + 8) = 0;
    _ZN13SafeAllocator21ResetAllocatorPointerEv((char *)object + 0xc);
    *(unsigned int *)(object + 0x20) = 0;
    object[0x24] = 0xff;
}
