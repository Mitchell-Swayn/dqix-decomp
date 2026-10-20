#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2291e3c; symbol: data_ov031_02291e3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage;
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" void _ZN13SafeAllocator4FreeEPv(void *, void *);
extern "C" int _Z20SetIRQInterruptStatei(int);
// Original: arm9/ov031 @ 0x02243484; symbol: Memory_FreeWithIRQDisabled; size: 0x30.
// For non-null input, disables IRQs, frees through the overlay SafeAllocator, then restores IRQ state.
extern "C" void Memory_FreeWithIRQDisabled(void *unused, void *ptr) {
    if (ptr == 0) return;
    int state = _Z20DisableIRQInterruptsv();
    _ZN13SafeAllocator4FreeEPv((void *)&MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage, ptr);
    _Z20SetIRQInterruptStatei(state);
}
