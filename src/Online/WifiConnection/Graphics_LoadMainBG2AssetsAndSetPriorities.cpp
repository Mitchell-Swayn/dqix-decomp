#include <globaldefs.h>
ARM
extern "C" char Graphics_LoadMainBG2AssetsAndSetPriorities_PathCharXb3MultiNscL[];
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned int,unsigned int);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(const void*,void(*)(const void*,unsigned int,unsigned int));
extern "C" char Graphics_LoadMainBG2AssetsAndSetPriorities_PathCharJbBgStep2NcgL[],Graphics_LoadMainBG2AssetsAndSetPriorities_PathCharYbBgStep2NclL[];
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned int,unsigned int);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned int,unsigned int);
struct Control { unsigned short priority:2;unsigned short rest:14; };
// Original: arm9/ov031 @ 0x02234570; symbol: func_ov031_02234570; size: 0xA8.
extern "C" void Graphics_LoadMainBG2AssetsAndSetPriorities() {
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainBG2AssetsAndSetPriorities_PathCharJbBgStep2NcgL,LoadToMainBG2CharacterData);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainBG2AssetsAndSetPriorities_PathCharYbBgStep2NclL,LoadToMainBGStandardPalette);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainBG2AssetsAndSetPriorities_PathCharXb3MultiNscL,LoadToMainBG2ScreenData);
((volatile Control*)0x4001008)->priority=3;
((volatile Control*)0x400100a)->priority=3;
((volatile Control*)0x4000008)->priority=3;
((volatile Control*)0x400000a)->priority=3;
((volatile Control*)0x400000c)->priority=3;
}
