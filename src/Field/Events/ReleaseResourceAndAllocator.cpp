#include <globaldefs.h>
ARM
extern "C" void VRAMBankConfig_Reset(void *);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021C0364; symbol: func_ov017_021c0364; size: 0x40.
extern "C" void ReleaseResourceAndAllocator(void *self) {
    if (*(void **)((unsigned char *)self + 0x1c) != 0)
        VRAMBankConfig_Reset(*(void **)((unsigned char *)self + 0x1c));
    void *allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((unsigned char *)self + 8);
    _ZN13SafeAllocator7DestroyEv((unsigned char *)self + 8);
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
}
