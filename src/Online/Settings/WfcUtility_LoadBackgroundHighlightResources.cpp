#include <globaldefs.h>
ARM
#pragma force_active on

// Original data: arm9/ov031 @ 0x02250BF4; symbol: data_ov031_02250bf4.
// Zero-initialized resource pointer, allocated here as 0xC0 bytes.
extern "C" void *LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x0224B410; symbol: data_ov031_0224b410.
// Initialized localized background character path; see docs/data-symbols/ov031.md.
extern "C" char WfcUtility_LoadBackgroundHighlightResources_PathCharJbBgHlNcgL[];
// Original data: arm9/ov031 @ 0x0224B3C0; symbol: data_ov031_0224b3c0.
// Initialized resource path pointer table; selectors zero and one use the first two entries.
extern "C" void *SystemCreateCopyAndFinalizeResource_HelpOverlayResourcePathsIndexedByHelpTopic[];
extern "C" void *Memory_AllocateZeroedBlock(unsigned, unsigned);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void *, void (*)(void *, int, unsigned));
extern "C" void LoadToMainBG1CharacterData(void *, int, unsigned);
extern "C" void LoadToMainBG1ScreenData(void *, int, unsigned);
extern "C" unsigned WfcUtility_GetInitialMenuSelector(void);
// Original: arm9/ov031 @ 0x0222390C; symbol: func_ov031_0222390c; size: 0x78.
// Allocates highlight storage, loads background characters and selects screen data from the menu selector.
extern "C" void WfcUtility_LoadBackgroundHighlightResources(void)
{
    LoadAndSelectMainBG1Data_UnknownRoleZeroInitializedStorage = Memory_AllocateZeroedBlock(0xc0, 4);
    WfcUtility_LoadLocalizedResourceAndApply(WfcUtility_LoadBackgroundHighlightResources_PathCharJbBgHlNcgL, LoadToMainBG1CharacterData);
    switch (WfcUtility_GetInitialMenuSelector()) {
    case 0:
        WfcUtility_LoadLocalizedResourceAndApply(SystemCreateCopyAndFinalizeResource_HelpOverlayResourcePathsIndexedByHelpTopic[0], LoadToMainBG1ScreenData);
        break;
    case 1:
        WfcUtility_LoadLocalizedResourceAndApply(SystemCreateCopyAndFinalizeResource_HelpOverlayResourcePathsIndexedByHelpTopic[1], LoadToMainBG1ScreenData);
        break;
    }
}
#pragma force_active reset
