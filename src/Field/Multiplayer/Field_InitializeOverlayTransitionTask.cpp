#include <globaldefs.h>
extern "C" void LinkedQueue_InitializeNodeStatus(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original data: arm9/ov017 @ 0x21d83ec; symbol: data_ov017_021d83ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned int KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage;
// The external word and cleared fields retain offset-based descriptions.
// Original: arm9/ov017 @ 0x021b14a0; symbol: func_ov017_021b14a0; size: 0x4c.
extern "C" void Field_InitializeOverlayTransitionTask(unsigned char* p) {
    LinkedQueue_InitializeNodeStatus(p);
    p[0] = 0x2b;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 8);
    *(unsigned*)(p + 0x1c) = 0;
    KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage = 0;
    p[0x30] = 0;
    p[0x31] = 0;
    p[0x48] = 0;
    p[0x49] = 1;
    p[0x4a] = 0;
}
