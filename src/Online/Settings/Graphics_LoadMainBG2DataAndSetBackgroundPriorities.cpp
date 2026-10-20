#include <globaldefs.h>
ARM
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());
extern "C" void LoadToMainBG2ScreenData();
extern "C" unsigned char Graphics_LoadMainBG2DataAndSetBackgroundPriorities_PathCharJb4ErrorNscL[];
// Original: arm9/ov031 @ 0x0222E404; symbol: func_ov031_0222e404; size: 0x80.
extern "C" void Graphics_LoadMainBG2DataAndSetBackgroundPriorities(){
 WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainBG2DataAndSetBackgroundPriorities_PathCharJb4ErrorNscL,LoadToMainBG2ScreenData);
 volatile unsigned short* sub=(volatile unsigned short*)0x04001008;
 volatile unsigned short* main=(volatile unsigned short*)0x0400000a;
 sub[0]=(sub[0]&~3)|3;
 sub[1]=(sub[1]&~3)|3;
 *(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|3;
 main[0]=(main[0]&~3)|3;
 main[1]=(main[1]&~3)|3;
}
