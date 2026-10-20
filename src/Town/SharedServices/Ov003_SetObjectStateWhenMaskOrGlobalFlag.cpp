#include <globaldefs.h>
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short *, unsigned int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/ov003 @ 0x0217C74C; symbol: func_ov003_0217c74c; size: 0x54.
extern "C" void Ov003_SetObjectStateWhenMaskOrGlobalFlag(void *object) {
    if (Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x0c0f) == 0) {
        if (Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] == 0 || *(unsigned short *)(Main_UnknownRoleZeroInitializedStorage_Variant4 + 0x24) == 0) return;
    }
    *(unsigned char *)((char *)object + 0x140) = 4;
    *(unsigned char *)((char *)object + 0x141) = 0;
}
