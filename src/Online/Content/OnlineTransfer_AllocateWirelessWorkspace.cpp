#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
// Original data: arm9/ov031 @ 0x2291e3c; symbol: data_ov031_02291e3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02243450; symbol: func_ov031_02243450; size: 0x34.
extern "C" char* OnlineTransfer_AllocateWirelessWorkspace(unsigned unused, unsigned size) {
    int irqState = _Z20DisableIRQInterruptsv();
    char* result = _ZN13SafeAllocator8AllocateEj((unsigned)MemoryFreeWithIRQDisabled_UnknownRoleZeroInitializedStorage, size);
    _Z20SetIRQInterruptStatei(irqState);
    return result;
}
