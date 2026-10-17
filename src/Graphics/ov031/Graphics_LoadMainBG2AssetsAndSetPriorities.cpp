#include <globaldefs.h>
ARM
extern "C" char data_ov031_0224bdf8[];
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned int,unsigned int);
extern "C" void System_LoadResourceAndInvokeCallback(const void*,void(*)(const void*,unsigned int,unsigned int));
extern "C" char data_ov031_0224bdc8[],data_ov031_0224bde0[];
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned int,unsigned int);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned int,unsigned int);
struct Control { unsigned short priority:2;unsigned short rest:14; };
// Original: arm9/ov031 @ 0x02234570; symbol: func_ov031_02234570; size: 0xA8.
extern "C" void Graphics_LoadMainBG2AssetsAndSetPriorities() {
System_LoadResourceAndInvokeCallback(data_ov031_0224bdc8,LoadToMainBG2CharacterData);
System_LoadResourceAndInvokeCallback(data_ov031_0224bde0,LoadToMainBGStandardPalette);
System_LoadResourceAndInvokeCallback(data_ov031_0224bdf8,LoadToMainBG2ScreenData);
((volatile Control*)0x4001008)->priority=3;
((volatile Control*)0x400100a)->priority=3;
((volatile Control*)0x4000008)->priority=3;
((volatile Control*)0x400000a)->priority=3;
((volatile Control*)0x400000c)->priority=3;
}
