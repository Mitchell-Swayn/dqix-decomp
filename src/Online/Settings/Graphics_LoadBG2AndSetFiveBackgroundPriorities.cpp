#include <globaldefs.h>
ARM
extern "C" {extern char Graphics_LoadBG2AndSetFiveBackgroundPriorities_PathCharYb5MultiNscL[];void LoadToMainBG2ScreenData();void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());}
// Original: arm9/ov031 @ 0x022285E4; symbol: func_ov031_022285e4; size: 0x80.
extern "C" void Graphics_LoadBG2AndSetFiveBackgroundPriorities(){
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadBG2AndSetFiveBackgroundPriorities_PathCharYb5MultiNscL,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
