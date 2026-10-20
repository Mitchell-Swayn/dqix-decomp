// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char RTCGetDate_UnknownRoleZeroInitializedStorage[];void ActorPool_ResetSpriteResourceDirectory(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x0204A60C; symbol: func_0204a60c; size: 0x1C.
extern "C" void SubBackground3_SetPriority(unsigned v){volatile unsigned short* p=(volatile unsigned short*)0x400100e;*p=(*p&~3)|v;}
