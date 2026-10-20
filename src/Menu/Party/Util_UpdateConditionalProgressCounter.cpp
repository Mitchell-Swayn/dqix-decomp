#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short* p,unsigned int mask);
extern "C" int TouchInput_IsNewPress(unsigned char *p);
extern "C" unsigned int TextContext_GetSharedInstance();
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/ov002 @ 0x0216885C; symbol: func_ov002_0216885c; size: 0x9C.
extern "C" void Util_UpdateConditionalProgressCounter(unsigned char *self) {
    char *context = (char*)TextContext_GetSharedInstance();
    if (*(int*)(context + 0x998)) {
        if (self[0x2454] >= self[0x2455]) ++*(int*)(self + 0x1bc0);
        if (*(int*)(context + 0x9a0) == 3) {
            if (Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x603) || TouchInput_IsNewPress(Main_UnknownRoleZeroInitializedStorage_Variant4))
                --*(int*)(self + 0x1bc0);
        }
    } else {
        ++*(int*)(self + 0x1bc0);
    }
}
