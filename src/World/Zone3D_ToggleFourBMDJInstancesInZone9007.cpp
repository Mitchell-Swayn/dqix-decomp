#include <globaldefs.h>
ARM
extern "C" char* Zone3D_GetMainInstance();extern "C" unsigned short* _ZN6Zone3D16FindBMDJInstanceEit(void*,int,unsigned short);extern "C" int GameResources_IsCurrentSceneTypeFour();extern "C" void GameState_SetIndexedFlagAndNotifyOverlay(int,bool);
// Original: arm9/main @ 0x020AE880; symbol: func_020ae880; size: 0x110.
extern "C" void Zone3D_ToggleFourBMDJInstancesInZone9007(int enabled){char* zone=Zone3D_GetMainInstance();if(*(unsigned short*)zone!=9007)return;unsigned short* a=_ZN6Zone3D16FindBMDJInstanceEit(zone,0,5);unsigned short* b=_ZN6Zone3D16FindBMDJInstanceEit(zone,0,3);unsigned short* c=_ZN6Zone3D16FindBMDJInstanceEit(zone,0,15);unsigned short* d=_ZN6Zone3D16FindBMDJInstanceEit(zone,0,17);if(!a||!b||!c||!d)return;if(!GameResources_IsCurrentSceneTypeFour()){if(!enabled){b[1]&=~4;d[1]&=~4;c[1]|=4;a[1]|=4;}else{b[1]|=4;d[1]|=4;c[1]&=~4;a[1]&=~4;}}GameState_SetIndexedFlagAndNotifyOverlay(12,enabled!=0);}
