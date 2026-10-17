#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void System_LoadResourceAndInvokeCallback(const void*,void(*)(const void*,unsigned,unsigned));
extern "C" char data_ov031_0224ba0c[];
extern "C" void LoadToMainObjStandardPalette(const void*,unsigned,unsigned);
extern "C" char data_ov031_0224ba20[];
extern "C" char data_ov031_0224ba38[];
extern "C" char data_ov031_0224ba50[];
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned,unsigned);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned,unsigned);
// Original: arm9/ov031 @ 0x0222CD14; symbol: func_ov031_0222cd14; size: 0xBC.
extern "C" void Graphics_LoadMainObjectPaletteAndBG2Resources() {
System_LoadResourceAndInvokeCallback(data_ov031_0224ba0c,LoadToMainObjStandardPalette);
System_LoadResourceAndInvokeCallback(data_ov031_0224ba20,LoadToMainBG2CharacterData);
System_LoadResourceAndInvokeCallback(data_ov031_0224ba38,LoadToMainBGStandardPalette);
System_LoadResourceAndInvokeCallback(data_ov031_0224ba50,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|2;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
