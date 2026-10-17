#include <globaldefs.h>
#include <Resource/Brightness.h>
ARM
// Original: arm9/main @ 0x020DB844; symbol: func_020db844; size: 0x50.
extern "C" void Graphics_SetSelectedScreenBrightnessAndMarkEnabled(char *p, int sub, int value, int duration) {
    GameResources *resources=GameResources_GetInstance(); if (!resources) return; p[0x6c]=0;
    if (sub == 0) SetMainBrightness(resources,value,duration); else SetSubBrightness(resources,value,duration);
    p[0x6c]=1;
}
