#include <globaldefs.h>
ARM
extern "C" {extern char Graphics_LoadThreeBGAssetsAndSetPriorities_PathCharJbBgStep3NcgL[];extern char Graphics_LoadThreeBGAssetsAndSetPriorities_PathCharYbBgStep3NclL[];extern char Graphics_LoadThreeBGAssetsAndSetPriorities_PathCharXb4MultiNscL[];void LoadToMainBG2CharacterData();void LoadToMainBGStandardPalette();void LoadToMainBG2ScreenData();void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());}
// Original: arm9/ov031 @ 0x0222AF14; symbol: func_ov031_0222af14; size: 0xA8.
extern "C" void Graphics_LoadThreeBGAssetsAndSetPriorities(){
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadThreeBGAssetsAndSetPriorities_PathCharJbBgStep3NcgL,LoadToMainBG2CharacterData);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadThreeBGAssetsAndSetPriorities_PathCharYbBgStep3NclL,LoadToMainBGStandardPalette);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadThreeBGAssetsAndSetPriorities_PathCharXb4MultiNscL,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
