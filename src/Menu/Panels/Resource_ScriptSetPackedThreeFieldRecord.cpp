#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
struct Packed { char pad[0xf4]; unsigned field0 : 12; unsigned field1 : 4; unsigned field2 : 5; unsigned rest : 11; };
struct Context { unsigned char a,b,enabled,c; unsigned words[2]; Packed *record; };
// Original data: arm9/ov023 @ 0x21fff08; symbol: data_ov023_021fff08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Context ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov023 @ 0x021F55E8; symbol: func_ov023_021f55e8; size: 0x98.
extern "C" int Resource_ScriptSetPackedThreeFieldRecord(char *params) {
    if (!ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.enabled) return 1;
    ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.record->field0 = _ZNK6Script9Parameter5ToIntEv(params);
    ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.record->field1 = _ZNK6Script9Parameter5ToIntEv(params + 8);
    ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.record->field2 = _ZNK6Script9Parameter5ToIntEv(params + 16);
    return 1;
}
