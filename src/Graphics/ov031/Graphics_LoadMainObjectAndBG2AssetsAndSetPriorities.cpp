#include <globaldefs.h>
ARM
extern "C" char data_ov031_0224bac4[];
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned int,unsigned int);
extern "C" void System_LoadResourceAndInvokeCallback(const void*,void(*)(const void*,unsigned int,unsigned int));
extern "C" char data_ov031_0224ba94[],data_ov031_0224baac[];
extern "C" void LoadToMainBG2CharacterData(const void*,unsigned int,unsigned int);
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned int,unsigned int);
extern "C" char data_ov031_0224ba80[];
extern "C" void LoadToMainObjStandardPalette(const void*,unsigned int,unsigned int);
struct Control { unsigned short priority:2;unsigned short rest:14; };
// Original: arm9/ov031 @ 0x0222D894; symbol: func_ov031_0222d894; size: 0xBC.
extern "C" void Graphics_LoadMainObjectAndBG2AssetsAndSetPriorities() {
System_LoadResourceAndInvokeCallback(data_ov031_0224ba80,LoadToMainObjStandardPalette);
System_LoadResourceAndInvokeCallback(data_ov031_0224ba94,LoadToMainBG2CharacterData);
System_LoadResourceAndInvokeCallback(data_ov031_0224baac,LoadToMainBGStandardPalette);
System_LoadResourceAndInvokeCallback(data_ov031_0224bac4,LoadToMainBG2ScreenData);
((volatile Control*)0x4001008)->priority=3;
((volatile Control*)0x400100a)->priority=3;
((volatile Control*)0x4000008)->priority=2;
((volatile Control*)0x400000a)->priority=3;
((volatile Control*)0x400000c)->priority=3;
}
