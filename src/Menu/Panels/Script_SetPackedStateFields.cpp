#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
struct PackedState { char pad[0x100]; unsigned low : 12; unsigned middle : 4; unsigned high : 5; unsigned reserved : 11; };
struct Root { char pad[12]; PackedState *state; };
// Original data: arm9/ov023 @ 0x21fff08; symbol: data_ov023_021fff08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Root ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov023 @ 0x021F57C4; symbol: func_ov023_021f57c4; size: 0x84.
extern "C" int Script_SetPackedStateFields(char *params) {
    ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.state->low = _ZNK6Script9Parameter5ToIntEv(params);
    ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.state->middle = _ZNK6Script9Parameter5ToIntEv(params + 8);
    ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.state->high = _ZNK6Script9Parameter5ToIntEv(params + 16);
    return 1;
}
