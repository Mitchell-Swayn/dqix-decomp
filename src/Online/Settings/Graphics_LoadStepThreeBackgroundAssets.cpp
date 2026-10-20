#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned,unsigned);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned,unsigned);
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(const char*,void(*)(const void*,unsigned,unsigned));
extern "C" char Graphics_LoadStepThreeBackgroundAssets_PathCharJbBgStep3NcgL[],Graphics_LoadStepThreeBackgroundAssets_PathCharYbBgStep3NclL[],Graphics_LoadStepThreeBackgroundAssets_PathCharXb4NoneNscL[];
// Original: arm9/ov031 @ 0x02230F20; symbol: func_ov031_02230f20; size: 0x94.
extern "C" void Graphics_LoadStepThreeBackgroundAssets() {
    WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadStepThreeBackgroundAssets_PathCharJbBgStep3NcgL,LoadToMainBG2CharacterData);
    WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadStepThreeBackgroundAssets_PathCharYbBgStep3NclL,LoadToMainBGStandardPalette);
    WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadStepThreeBackgroundAssets_PathCharXb4NoneNscL,LoadToMainBG2ScreenData);
    volatile unsigned short *sub = (volatile unsigned short*)0x04001008;
    volatile unsigned short *main = (volatile unsigned short*)0x0400000a;
    sub[0] = (sub[0] & ~3) | 3;
    sub[1] = (sub[1] & ~3) | 3;
    main[0] = (main[0] & ~3) | 3;
    main[1] = (main[1] & ~3) | 3;
}
