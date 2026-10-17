#include <globaldefs.h>
ARM
extern "C" void System_LoadResourceAndInvokeCallback(void*,void(*)());
extern "C" void LoadToMainBG2ScreenData();
extern "C" void LoadToMainBG2CharacterData();
extern "C" void LoadToMainBGStandardPalette();
extern "C" unsigned char data_ov031_0224bc50[],data_ov031_0224bc68[],data_ov031_0224bc80[];
// Original: arm9/ov031 @ 0x0223208C; symbol: func_ov031_0223208c; size: 0xA8.
extern "C" void Graphics_LoadMainBG2ResourcesAndSetPriorities(){
 System_LoadResourceAndInvokeCallback(data_ov031_0224bc50,LoadToMainBG2CharacterData);
 System_LoadResourceAndInvokeCallback(data_ov031_0224bc68,LoadToMainBGStandardPalette);
 System_LoadResourceAndInvokeCallback(data_ov031_0224bc80,LoadToMainBG2ScreenData);
 volatile unsigned short* sub=(volatile unsigned short*)0x04001008;
 volatile unsigned short* main=(volatile unsigned short*)0x0400000a;
 sub[0]=(sub[0]&~3)|3;
 sub[1]=(sub[1]&~3)|3;
 *(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
 main[0]=(main[0]&~3)|3;
 main[1]=(main[1]&~3)|3;
}
