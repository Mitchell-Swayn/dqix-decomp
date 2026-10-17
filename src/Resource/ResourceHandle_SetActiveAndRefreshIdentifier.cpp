#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" void UpdateByteLevelTransitionAndThreeChannels(void*,unsigned char,int);struct Owner{char pad[200];unsigned char first:1;unsigned char active:1;unsigned char rest:6;char gap[4];unsigned char id;};
// Original: arm9/main @ 0x0209CAA0; symbol: func_0209caa0; size: 0x48.
extern "C" ARM void ResourceHandle_SetActiveAndRefreshIdentifier(Owner* owner,int active){if(owner->active==active)return;owner->active=active!=0;UpdateByteLevelTransitionAndThreeChannels(owner,owner->id,30);}
