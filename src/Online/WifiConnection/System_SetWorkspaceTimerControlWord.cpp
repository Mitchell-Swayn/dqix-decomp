#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0220D8D4; symbol: func_ov031_0220d8d4; size: 0x20.
extern "C" void System_SetWorkspaceTimerControlWord(void) { *(unsigned int*)((char*)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage[0] + 0x2264) = 0x00aaa082; }
