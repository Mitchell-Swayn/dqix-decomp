#include <globaldefs.h>
ARM
extern "C" {extern char WfcUtility_LoadResponsePromptBackground_PathCharYb5MultiNscL[];void LoadToMainBG2ScreenData();void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());}
// Original: arm9/ov031 @ 0x0222A398; symbol: func_ov031_0222a398; size: 0x80.
extern "C" void WfcUtility_LoadResponsePromptBackground(){
WfcUtility_LoadLocalizedResourceAndApply(WfcUtility_LoadResponsePromptBackground_PathCharYb5MultiNscL,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
