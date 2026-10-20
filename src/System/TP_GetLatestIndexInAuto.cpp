#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char TPWaitBusy_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020CDDDC; symbol: func_020cdddc; size: 0x10.
extern "C" unsigned short TP_GetLatestIndexInAuto() { return *(unsigned short*)(TPWaitBusy_UnknownRoleZeroInitializedStorage+16); }
