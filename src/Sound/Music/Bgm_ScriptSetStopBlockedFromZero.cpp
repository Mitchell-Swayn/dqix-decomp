#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void*);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov001 @ 0x02163AB4; symbol: Script_SetParameterZeroFlag; size: 0x38.
extern "C" int Bgm_ScriptSetStopBlockedFromZero(void* parameter) {
    int value = Script_ReadParameterAsInteger(parameter);
    unsigned set = value == 0;
    unsigned char old = Main_UnknownRoleZeroInitializedStorage_Variant2[0xc8];
    Main_UnknownRoleZeroInitializedStorage_Variant2[0xc8] = (unsigned char)((old & ~4) | ((set << 31) >> 29));
    return 1;
}
