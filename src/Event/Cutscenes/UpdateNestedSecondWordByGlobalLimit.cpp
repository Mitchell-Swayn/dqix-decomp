#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov001 @ 0x0215AEB8; symbol: func_ov001_0215aeb8; size: 0x38.
extern "C" int UpdateNestedSecondWordByGlobalLimit(void* object) {
    int enabled = 0;
    if (Main_UnknownRoleZeroInitializedStorage_Variant4[0x54] != 0 && *(unsigned*)(Main_UnknownRoleZeroInitializedStorage_Variant4 + 0x44) < 0xa) enabled = 1;
    Script_WriteIntegerReferenceOutput(object, enabled);
    return 1;
}
