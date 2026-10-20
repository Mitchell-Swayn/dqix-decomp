#include <globaldefs.h>
ARM
// Original data: arm9/ov023 @ 0x21fff08; symbol: data_ov023_021fff08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern unsigned char ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[];
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
// Original: arm9/ov023 @ 0x021F55B8; symbol: func_ov023_021f55b8; size: 0x30.
extern "C" int Script_StoreParameterIntToConfiguredHalfword(const void *parameter) {
    if (ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[2]) {
        int value = _ZNK6Script9Parameter5ToIntEv(parameter);
        unsigned short *destination = *(unsigned short **)(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage + 0xc);
        *destination = (unsigned short)value;
    }
    return 1;
}
