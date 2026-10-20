#include <globaldefs.h>
extern "C" void LinkedQueue_InitializeNodeStatus(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// The meanings of the byte fields remain unknown.
// Original: arm9/ov017 @ 0x021c2b28; symbol: func_ov017_021c2b28; size: 0x44.
extern "C" void PartyRecovery_InitializePresentationRequest(unsigned char* p, unsigned char a, unsigned char b) {
    LinkedQueue_InitializeNodeStatus(p);
    p[0] = 0x46;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 8);
    p[0x8c] = 0;
    p[0x8d] = 0;
    *(unsigned*)(p + 0x90) = 0;
    p[0x96] = 0;
    p[0x94] = a;
    p[0x95] = b;
}
