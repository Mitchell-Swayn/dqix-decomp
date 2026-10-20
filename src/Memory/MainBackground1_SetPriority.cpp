// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char RTCGetDate_UnknownRoleZeroInitializedStorage[];void ActorPool_ResetSpriteResourceDirectory(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x0204A6B4; symbol: func_0204a6b4; size: 0x1C.
extern "C" void MainBackground1_SetPriority(unsigned v){volatile unsigned short* p=(volatile unsigned short*)0x400000a;*p=(*p&~3)|v;}
