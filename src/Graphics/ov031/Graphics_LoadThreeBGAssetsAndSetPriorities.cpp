#include <globaldefs.h>
ARM
extern "C" {extern char data_ov031_0224b99c[];extern char data_ov031_0224b9b4[];extern char data_ov031_0224b9cc[];void LoadToMainBG2CharacterData();void LoadToMainBGStandardPalette();void LoadToMainBG2ScreenData();void System_LoadResourceAndInvokeCallback(void*,void(*)());}
// Original: arm9/ov031 @ 0x0222AF14; symbol: func_ov031_0222af14; size: 0xA8.
extern "C" void Graphics_LoadThreeBGAssetsAndSetPriorities(){
System_LoadResourceAndInvokeCallback(data_ov031_0224b99c,LoadToMainBG2CharacterData);
System_LoadResourceAndInvokeCallback(data_ov031_0224b9b4,LoadToMainBGStandardPalette);
System_LoadResourceAndInvokeCallback(data_ov031_0224b9cc,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
