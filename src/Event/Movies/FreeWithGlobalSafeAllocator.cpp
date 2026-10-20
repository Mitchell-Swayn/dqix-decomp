#include <globaldefs.h>
ARM
// Original data: arm9/ov016 @ 0x219d0c0; symbol: data_ov016_0219d0c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" void *MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[];
extern "C" void _ZN13SafeAllocator4FreeEPv(void *, void *);
// Original: arm9/ov016 @ 0x0218BCA8; symbol: func_ov016_0218bca8; size: 0x1C.
extern "C" void FreeWithGlobalSafeAllocator(void *allocation) {
    _ZN13SafeAllocator4FreeEPv(MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[2], allocation);
}
