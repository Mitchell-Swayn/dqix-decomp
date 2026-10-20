#include <globaldefs.h>
ARM
// Original: arm9/ov003:0215e4e4; Narrows the integer parameter to signed 16-bit, creates linked coordinate halfword entries, and returns one.
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Script_CreateLinkedCoordinateHalfwordEntries(void *self, unsigned allocator, int count);
// Original data: arm9/ov003 @ 0x2180cb8; symbol: data_ov003_02180cb8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern unsigned int ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage[];
extern "C" int Script_CreateLinkedCoordinateEntriesFromParameter(const void *parameter) {
    int raw = _ZNK6Script9Parameter5ToIntEv(parameter);
    int count = (raw << 16) >> 16;
    Script_CreateLinkedCoordinateHalfwordEntries((void *)ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage[1], ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage[0], count);
    return 1;
}
