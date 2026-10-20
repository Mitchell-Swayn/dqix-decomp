// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char RTCGetDate_UnknownRoleZeroInitializedStorage[];void ActorPool_ResetSpriteResourceDirectory(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x020DAF6C; symbol: func_020daf6c; size: 0x14.
extern "C" unsigned Graphics_ReadMainDisplayLayerMask(){return (*(volatile unsigned*)0x4000000&0x1f00)>>8;}
