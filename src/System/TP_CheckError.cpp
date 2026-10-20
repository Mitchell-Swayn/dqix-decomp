#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char TPWaitBusy_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020CE114; symbol: func_020ce114; size: 0x14.
extern "C" unsigned int TP_CheckError(unsigned int mask) { return *(unsigned short*)(TPWaitBusy_UnknownRoleZeroInitializedStorage+0x38)&mask; }
