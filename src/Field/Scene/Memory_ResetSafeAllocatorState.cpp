#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original: arm9/ov017 @ 0x021BAC58; symbol: func_ov017_021bac58; size: 0x34.
extern "C" void Memory_ResetSafeAllocatorState(char* p) {
    LinkedQueue_InitializeNodeStatus((signed char*)p);
    p[0] = 0xf;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 0xc);
    *(unsigned int*)(p + 8) = 0;
    *(unsigned int*)(p + 0x20) = 0;
    *(volatile unsigned char*)(p + 0x24) = 0xff;
}
