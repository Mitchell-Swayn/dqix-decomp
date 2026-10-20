#include <globaldefs.h>
ARM

extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" void ResourceHandle_ResetSlotsAndReleaseState(void *);
extern "C" void Bgm_ReleaseArchiveController(void *);
extern "C" void Bgm_LoadArchiveIntoLargeOverlayBuffer(void *);
extern "C" void ResourceHandle_InitializeFromOverlayDataAnd57000Buffer(void *);
extern "C" void SoundSfx_LoadNormalOrBattleArchive(void *, int);
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

// Original: arm9/ov001 @ 0x02163A5C; symbol: func_ov001_02163a5c; size: 0x58.
extern "C" int Resource_ResetOrInitializeFromScriptParameter(void *parameter) {
    if (Script_ReadParameterAsInteger(parameter) != 0) {
        ResourceHandle_ResetSlotsAndReleaseState(Main_UnknownRoleZeroInitializedStorage);
        Bgm_ReleaseArchiveController(Main_UnknownRoleZeroInitializedStorage_Variant2);
        Bgm_LoadArchiveIntoLargeOverlayBuffer(Main_UnknownRoleZeroInitializedStorage_Variant2);
    } else {
        Bgm_ReleaseArchiveController(Main_UnknownRoleZeroInitializedStorage_Variant2);
        ResourceHandle_InitializeFromOverlayDataAnd57000Buffer(Main_UnknownRoleZeroInitializedStorage_Variant2);
        SoundSfx_LoadNormalOrBattleArchive(Main_UnknownRoleZeroInitializedStorage, 100);
    }
    return 1;
}
