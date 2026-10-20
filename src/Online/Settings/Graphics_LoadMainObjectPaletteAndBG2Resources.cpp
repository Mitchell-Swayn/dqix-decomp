#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(const void*,void(*)(const void*,unsigned,unsigned));
extern "C" char Graphics_LoadMainObjectPaletteAndBG2Resources_PathCharYbObjKbNclL[];
extern "C" void LoadToMainObjStandardPalette(const void*,unsigned,unsigned);
extern "C" char Graphics_LoadMainObjectPaletteAndBG2Resources_PathCharJbBgStep3NcgL[];
extern "C" char Graphics_LoadMainObjectPaletteAndBG2Resources_PathCharYbBgStep3NclL[];
extern "C" char Graphics_LoadMainObjectPaletteAndBG2Resources_PathCharXb4EditNscL[];
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned,unsigned);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned,unsigned);
// Original: arm9/ov031 @ 0x0222CD14; symbol: func_ov031_0222cd14; size: 0xBC.
extern "C" void Graphics_LoadMainObjectPaletteAndBG2Resources() {
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainObjectPaletteAndBG2Resources_PathCharYbObjKbNclL,LoadToMainObjStandardPalette);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainObjectPaletteAndBG2Resources_PathCharJbBgStep3NcgL,LoadToMainBG2CharacterData);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainObjectPaletteAndBG2Resources_PathCharYbBgStep3NclL,LoadToMainBGStandardPalette);
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainObjectPaletteAndBG2Resources_PathCharXb4EditNscL,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|2;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
