#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
// Original data: arm9/ov003 @ 0x2180cb8; symbol: data_ov003_02180cb8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" unsigned int ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage[];
extern "C" void Resource_InitializeLinkedCoordinateAndHalfwordEntry(void *, unsigned int, int);

// Original: arm9/ov003 @ 0x0215E5FC; symbol: func_ov003_0215e5fc; size: 0x2C.
extern "C" int Resource_InitializeLinkedCoordinateAndHalfwordEntryFromParameter(const void *parameter) {
    Resource_InitializeLinkedCoordinateAndHalfwordEntry((void *)ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage[1], ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage[0], (short)_ZNK6Script9Parameter5ToIntEv(parameter));
    return 1;
}
