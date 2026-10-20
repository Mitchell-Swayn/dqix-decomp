#include <globaldefs.h>
ARM
extern "C" ARM void Bgm_SetPlaybackVolumeAndFade(unsigned char *, unsigned char, int);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov025 @ 0x021E8024; symbol: func_ov025_021e8024; size: 0x20.
extern "C" int Combat_FadeBgmPlaybackVolume(unsigned char *p) {
    Bgm_SetPlaybackVolumeAndFade(Main_UnknownRoleZeroInitializedStorage_Variant2, p[8], *(unsigned short *)(p + 0xa));
    return 1;
}
