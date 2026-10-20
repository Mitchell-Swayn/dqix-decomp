#include <Memory/SafeAllocator.h>

#pragma define_section init ".init" RX

extern "C" SafeAllocator* Allocator_ResetPointerAndReturnSelf(SafeAllocator* p);
// Original data: arm9/main @ 0x214e4c8; symbol: data_0214e4c8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 232 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char DisplayOverlayGetInstance_UnknownRoleZeroInitializedStorage[];

// Global constructor thunk for the allocator object at data_0214e4c8.
// Original: arm9/main @ 0x020E677C; symbol: __sinit_020e677c; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e677c()
{
    Allocator_ResetPointerAndReturnSelf((SafeAllocator*)DisplayOverlayGetInstance_UnknownRoleZeroInitializedStorage);
}
