// Reviewed original ARM access widths. MMIO addresses are original hardware literals; data target has original relocation.
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2111818; symbol: data_02111818.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char RTCGetDate_UnknownRoleZeroInitializedStorage[];void ActorPool_ResetSpriteResourceDirectory(void*);}struct TypeBits{unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x02068BC4; symbol: func_02068bc4; size: 0x18.
extern "C" int Object_TestWord8BCOutsideZeroOrOne(void*,char* p){int v=*(int*)(p+0x8bc);return v!=0&&v!=1;}
