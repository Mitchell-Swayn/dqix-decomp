#include <globaldefs.h>
ARM

extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
// Original data: arm9/ov017 @ 0x21d840c; symbol: data_ov017_021d840c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" int OverlayPopAndDestroyObject_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov017 @ 0x021B2C4C; symbol: func_ov017_021b2c4c; size: 0x3C.
extern "C" void FieldFacilityMenu_InitializeOverlayCommand(unsigned char *p) {
    LinkedQueue_InitializeNodeStatus((signed char *)p);
    p[0] = 0x12;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(p + 0xc);
    *(unsigned int *)(p + 8) = 0;
    OverlayPopAndDestroyObject_UnknownRoleZeroInitializedStorage = 0;
    p[0x20] = 0xff;
}
