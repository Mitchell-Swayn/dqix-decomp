#include <globaldefs.h>
// Original data: arm9/main @ 0x2105254; symbol: data_02105254.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int GraphicsGetGlobalBackgroundState_UnknownRoleZeroInitializedStorage;
extern "C" void Graphics_UpdateSelectedBackgroundTileBuffer(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
ARM
#pragma optimize_for_size off
// Original: arm9/main @ 0x0203BCB8; symbol: func_0203bcb8; size: 0x50.
extern "C" void Graphics_SubmitObjectBackgroundParameters(unsigned char *p, unsigned int a, unsigned int b) {
    Graphics_UpdateSelectedBackgroundTileBuffer((unsigned int)&GraphicsGetGlobalBackgroundState_UnknownRoleZeroInitializedStorage,*(unsigned short *)(p+0x16),*(unsigned short *)(p+0x18),a,b,*(unsigned int *)(p+8),p[0],p[1],*(unsigned short *)(p+0x14));
}
