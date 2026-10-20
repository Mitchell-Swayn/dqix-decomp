#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned Main_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" unsigned ResourceHandle_ReplaceValueAndInvalidateFileIndices(unsigned *, void *, unsigned);
// Original: arm9/ov001 @ 0x02163540; symbol: func_ov001_02163540; size: 0x24.
extern "C" unsigned Bgm_ScriptStopStreamWithFade(void *parameter) {
    unsigned value = Script_ReadParameterAsInteger(parameter);
    ResourceHandle_ReplaceValueAndInvalidateFileIndices(&Main_UnknownRoleZeroInitializedStorage_Variant2, 0, value);
    return 1;
}
