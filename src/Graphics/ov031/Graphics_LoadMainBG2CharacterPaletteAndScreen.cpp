#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void System_LoadResourceAndInvokeCallback(const void*,void(*)(const void*,unsigned,unsigned));
extern "C" char data_ov031_0224bc0c[];
extern "C" char data_ov031_0224bc24[];
extern "C" char data_ov031_0224bc3c[];
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned,unsigned);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned,unsigned);
// Original: arm9/ov031 @ 0x02231C0C; symbol: func_ov031_02231c0c; size: 0xA8.
extern "C" void Graphics_LoadMainBG2CharacterPaletteAndScreen() {
System_LoadResourceAndInvokeCallback(data_ov031_0224bc0c,LoadToMainBG2CharacterData);
System_LoadResourceAndInvokeCallback(data_ov031_0224bc24,LoadToMainBGStandardPalette);
System_LoadResourceAndInvokeCallback(data_ov031_0224bc3c,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
