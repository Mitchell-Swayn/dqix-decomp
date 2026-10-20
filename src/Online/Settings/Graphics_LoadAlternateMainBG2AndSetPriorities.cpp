#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(const void*,void(*)(const void*,unsigned,unsigned));
extern "C" char Graphics_LoadAlternateMainBG2AndSetPriorities_PathCharJb5MoveNscL[];
// Original: arm9/ov031 @ 0x0222A794; symbol: func_ov031_0222a794; size: 0x80.
extern "C" void Graphics_LoadAlternateMainBG2AndSetPriorities() {
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadAlternateMainBG2AndSetPriorities_PathCharJb5MoveNscL,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
