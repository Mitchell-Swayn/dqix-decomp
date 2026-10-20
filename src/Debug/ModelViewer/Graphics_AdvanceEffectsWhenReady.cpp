#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short* p, unsigned mask);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void* object);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov015 @ 0x0218E5C0; symbol: func_ov015_0218e5c0; size: 0x4C.
extern "C" void Graphics_AdvanceEffectsWhenReady(void* self) {
    int shouldAdvance = 0;
    if (*(unsigned char*)((char*)self + 0x3A) != 0) {
        if (Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x100))
            shouldAdvance = 1;
    } else {
        shouldAdvance = 1;
    }
    if (shouldAdvance)
        _ZN8Object3D14AdvanceEffectsEv(*(void**)((char*)self + 0x24));
}
