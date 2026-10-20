#include <globaldefs.h>
ARM
extern "C" unsigned char Graphics_LoadMainBG2ScreenAndSetFiveBackgroundPriorities_PathCharYb5MultiNscL[];
extern "C" void LoadToMainBG2ScreenData();
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());
struct BG { unsigned short priority:2; unsigned short other:14; };
// Original: arm9/ov031 @ 0x022297AC; symbol: func_ov031_022297ac; size: 0x80.
extern "C" void Graphics_LoadMainBG2ScreenAndSetFiveBackgroundPriorities() {
 WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainBG2ScreenAndSetFiveBackgroundPriorities_PathCharYb5MultiNscL,LoadToMainBG2ScreenData);
 ((volatile BG*)0x04001008)->priority=3;
 ((volatile BG*)0x0400100a)->priority=3;
 ((volatile BG*)0x04000008)->priority=3;
 ((volatile BG*)0x0400000a)->priority=3;
 ((volatile BG*)0x0400000c)->priority=3;
}
