#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2291e3c; symbol: data_ov031_02291e3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage[];
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" void _ZN13SafeAllocator4FreeEPv(void *, void *);
extern "C" int _Z20SetIRQInterruptStatei(int);
// Original: arm9/ov031 @ 0x022434E8; symbol: func_ov031_022434e8; size: 0x30.
extern "C" void Memory_FreeSafeAllocatorPointer(void *unused, void *pointer) {
    if (pointer == 0)
        return;
    int irqState = _Z20DisableIRQInterruptsv();
    _ZN13SafeAllocator4FreeEPv(MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage, pointer);
    _Z20SetIRQInterruptStatei(irqState);
}
