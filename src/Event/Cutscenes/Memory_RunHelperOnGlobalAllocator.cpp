#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" void Resource_AllocateOverlayScriptObjectBuffers(void *);
// Original: arm9/ov001 @ 0x0215F2E8; symbol: func_ov001_0215f2e8; size: 0x1C.
extern "C" unsigned int Memory_RunHelperOnGlobalAllocator(void) {
    Resource_AllocateOverlayScriptObjectBuffers(*(void **)EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage);
    return 1;
}
