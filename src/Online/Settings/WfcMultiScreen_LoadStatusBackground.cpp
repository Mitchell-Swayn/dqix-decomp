#include <globaldefs.h>
ARM
extern "C" {extern char WfcMultiScreen_LoadStatusBackground_PathCharXb4MultiNscL[];void LoadToMainBG2ScreenData();void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());}
// Original: arm9/ov031 @ 0x02231594; symbol: func_ov031_02231594; size: 0x80.
extern "C" void WfcMultiScreen_LoadStatusBackground(){
WfcUtility_LoadLocalizedResourceAndApply(WfcMultiScreen_LoadStatusBackground_PathCharXb4MultiNscL,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
