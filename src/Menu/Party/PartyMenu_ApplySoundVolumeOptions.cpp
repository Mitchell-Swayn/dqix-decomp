#include <globaldefs.h>
ARM
extern "C" unsigned char SoundSfx_GetVolumeSetting(void *);
extern "C" void Bgm_SetVolumeSetting(void *, int);
extern "C" void SoundSfx_SetVolumeSetting(void *, int, ...);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char *, int, void *);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];

// Original: arm9/ov002 @ 0x0215B268; symbol: RefreshGlobalModesAndDispatchOnChange; size: 0x60.
// Refreshes global mode values from object +0x1C2C/+0x1C2D and dispatches global object 0x02108760 only when the state byte changed.
extern "C" void PartyMenu_ApplySoundVolumeOptions(void *object) {
    unsigned char old = SoundSfx_GetVolumeSetting(Main_UnknownRoleZeroInitializedStorage);
    Bgm_SetVolumeSetting(Main_UnknownRoleZeroInitializedStorage_Variant2, *((unsigned char *)object + 0x1c2c));
    SoundSfx_SetVolumeSetting(Main_UnknownRoleZeroInitializedStorage, *((unsigned char *)object + 0x1c2d));
    if (old != *((unsigned char *)object + 0x1c2d))
        SoundSfx_StartCurrentSequenceArchiveEntry((char *)Main_UnknownRoleZeroInitializedStorage, 1, 0);
}
