#include <globaldefs.h>
ARM
extern "C" {extern char WfcUtility_LoadUsbAccessPointSetupBackground_PathCharJbBgStep3NcgL[];extern char WfcUtility_LoadUsbAccessPointSetupBackground_PathCharYbBgStep3NclL[];extern char WfcUtility_LoadUsbAccessPointSetupBackground_PathCharJb4UsbNscL[];void LoadToMainBG2CharacterData();void LoadToMainBGStandardPalette();void LoadToMainBG2ScreenData();void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());}
// Original: arm9/ov031 @ 0x02234960; symbol: func_ov031_02234960; size: 0xA8.
extern "C" void WfcUtility_LoadUsbAccessPointSetupBackground(){
WfcUtility_LoadLocalizedResourceAndApply(WfcUtility_LoadUsbAccessPointSetupBackground_PathCharJbBgStep3NcgL,LoadToMainBG2CharacterData);
WfcUtility_LoadLocalizedResourceAndApply(WfcUtility_LoadUsbAccessPointSetupBackground_PathCharYbBgStep3NclL,LoadToMainBGStandardPalette);
WfcUtility_LoadLocalizedResourceAndApply(WfcUtility_LoadUsbAccessPointSetupBackground_PathCharJb4UsbNscL,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
