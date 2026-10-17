#include <globaldefs.h>
ARM
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
extern "C" void System_LoadResourceAndInvokeCallback(const void*,void(*)(const void*,unsigned,unsigned));
extern "C" char data_ov031_0224b898[];
// Original: arm9/ov031 @ 0x02228BE0; symbol: func_ov031_02228be0; size: 0x80.
extern "C" void Graphics_LoadMainBG2AndSetBackgroundPriorities() {
System_LoadResourceAndInvokeCallback(data_ov031_0224b898,LoadToMainBG2ScreenData);
*(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&~3)|3;
*(volatile unsigned short*)0x0400100a=(*(volatile unsigned short*)0x0400100a&~3)|3;
*(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
*(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|3;
*(volatile unsigned short*)0x0400000c=(*(volatile unsigned short*)0x0400000c&~3)|3;
}
