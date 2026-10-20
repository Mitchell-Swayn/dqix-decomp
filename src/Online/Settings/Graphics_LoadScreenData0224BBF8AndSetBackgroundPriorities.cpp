#include <globaldefs.h>
ARM
extern "C" unsigned char Graphics_LoadScreenData0224BBF8AndSetBackgroundPriorities_PathCharXb4MultiNscL[];
extern "C" void LoadToMainBG2ScreenData();
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());
struct BG { unsigned short priority:2; unsigned short other:14; };
// Original: arm9/ov031 @ 0x022319C4; symbol: func_ov031_022319c4; size: 0x80.
extern "C" void Graphics_LoadScreenData0224BBF8AndSetBackgroundPriorities() {
 WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadScreenData0224BBF8AndSetBackgroundPriorities_PathCharXb4MultiNscL,LoadToMainBG2ScreenData);
 ((volatile BG*)0x04001008)->priority=3;
 ((volatile BG*)0x0400100a)->priority=3;
 ((volatile BG*)0x04000008)->priority=3;
 ((volatile BG*)0x0400000a)->priority=3;
 ((volatile BG*)0x0400000c)->priority=3;
}
