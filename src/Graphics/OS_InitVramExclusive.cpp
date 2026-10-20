#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x211166c; symbol: data_0211166c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111670; symbol: data_02111670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned OSInitVramExclusive_UnknownRoleZeroInitializedStorage;extern "C" short OSInitVramExclusive_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/main @ 0x020C9A54; symbol: func_020c9a54; size: 0x34.
extern "C" void OS_InitVramExclusive(){OSInitVramExclusive_UnknownRoleZeroInitializedStorage=0;int i=0;do{short* slot=OSInitVramExclusive_UnknownRoleZeroInitializedStorage_Variant2+i++;*slot=0;}while(i<9);}
