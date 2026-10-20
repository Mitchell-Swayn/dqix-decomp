#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned Main_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" void Bgm_RequestTemporarySequence(int self, unsigned value);
// Original: arm9/ov001 @ 0x02163744; symbol: func_ov001_02163744; size: 0x20.
extern "C" unsigned Bgm_ScriptRequestTemporarySequence(void *parameter) {
    unsigned value = Script_ReadParameterAsInteger(parameter);
    Bgm_RequestTemporarySequence((int)&Main_UnknownRoleZeroInitializedStorage_Variant2, value);
    return 1;
}
