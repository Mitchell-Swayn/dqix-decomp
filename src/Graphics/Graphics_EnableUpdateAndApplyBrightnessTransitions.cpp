#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
void Stub(GameResources *);
extern "C" GameResources *GameResources_GetInstance();
// Original: arm9/main @ 0x020DB814; symbol: func_020db814; size: 0x30.
extern "C" void Graphics_EnableUpdateAndApplyBrightnessTransitions() { GameResources *p=GameResources_GetInstance(); if(!p) return; p->allowBrightnessApply=true; Stub(p); UpdateBrightnessTransitions(p); ApplyBrightness(p); }
