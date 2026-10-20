#include <globaldefs.h>
ARM
extern "C" char Graphics_LoadMainBG2ScreenAndSetPriorities_PathCharYb5MultiNscL[];
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned int,unsigned int);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(const void*,void(*)(const void*,unsigned int,unsigned int));
struct Control { unsigned short priority:2;unsigned short rest:14; };
// Original: arm9/ov031 @ 0x0222AB08; symbol: func_ov031_0222ab08; size: 0x80.
extern "C" void Graphics_LoadMainBG2ScreenAndSetPriorities() {
WfcUtility_LoadLocalizedResourceAndApply(Graphics_LoadMainBG2ScreenAndSetPriorities_PathCharYb5MultiNscL,LoadToMainBG2ScreenData);
((volatile Control*)0x4001008)->priority=3;
((volatile Control*)0x400100a)->priority=3;
((volatile Control*)0x4000008)->priority=3;
((volatile Control*)0x400000a)->priority=3;
((volatile Control*)0x400000c)->priority=3;
}
