#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ec; symbol: data_ov017_021d83ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void *KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage;
extern "C" void CutsceneCamera_ApplySelectedOrbitParameters(void *object);
// Original: arm9/ov017 @ 0x021B1CE4; symbol: func_ov017_021b1ce4; size: 0x20.
extern "C" void KrakPot_DrawFieldMenuSession(void) {
    if (KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage)
        CutsceneCamera_ApplySelectedOrbitParameters(KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage);
}
