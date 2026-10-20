#include <globaldefs.h>
ARM
extern "C" char Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities_PathCharXb4EditAddrNscL[];
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned int,unsigned int);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(const void*,void(*)(const void*,unsigned int,unsigned int));
extern "C" char Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities_PathCharJbBgStep3NcgL[],Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities_PathCharYbBgStep3NclL[];
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned int,unsigned int);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned int,unsigned int);
extern "C" char Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities_PathCharYbObjKbNclL[];
extern "C" void LoadToMainObjStandardPalette(const void*,unsigned int,unsigned int);
struct Control { unsigned short priority:2;unsigned short rest:14; };
// Original: arm9/ov031 @ 0x0222D894; symbol: func_ov031_0222d894; size: 0xBC.
extern "C" void Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities() {
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities_PathCharYbObjKbNclL,LoadToMainObjStandardPalette);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities_PathCharJbBgStep3NcgL,LoadToMainBG2CharacterData);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities_PathCharYbBgStep3NclL,LoadToMainBGStandardPalette);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities_PathCharXb4EditAddrNscL,LoadToMainBG2ScreenData);
((volatile Control*)0x4001008)->priority=3;
((volatile Control*)0x400100a)->priority=3;
((volatile Control*)0x4000008)->priority=2;
((volatile Control*)0x400000a)->priority=3;
((volatile Control*)0x400000c)->priority=3;
}
