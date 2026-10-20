#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short *, unsigned int);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void *);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov015 @ 0x0218E574; symbol: func_ov015_0218e574; size: 0x4C.
extern "C" void Ov015_AdvanceEffectsWhenActive(char *object) {
    int active = 0;
    if (*(unsigned char *)(object + 0x3a)) {
        if (Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x100)) active = 1;
    } else {
        active = 1;
    }
    if (active) _ZN8Object3D14AdvanceEffectsEv(*(void **)(object + 0x24));
}
