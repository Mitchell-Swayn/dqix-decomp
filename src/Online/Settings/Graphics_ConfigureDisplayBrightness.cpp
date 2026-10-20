#include <globaldefs.h>
ARM

extern "C" unsigned int Memory_AllocateZeroedBlock(unsigned, unsigned);
extern "C" void ColorEffect_ConfigureBrightnessAdjust(int, unsigned int, int);
// Original data: arm9/ov031 @ 0x2290d34; symbol: data_ov031_02290d34.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0223BFF8; symbol: func_ov031_0223bff8; size: 0x48.
extern "C" void Graphics_ConfigureDisplayBrightness(void) {
    WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage[0] = Memory_AllocateZeroedBlock(0x18, 4);
    ColorEffect_ConfigureBrightnessAdjust(0x04000050, 0x3F, 0x10);
    ColorEffect_ConfigureBrightnessAdjust(0x04001050, 0x3F, 0x10);
}
