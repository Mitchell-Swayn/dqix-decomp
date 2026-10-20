#include <globaldefs.h>
extern "C" unsigned short* Zone3D_GetMainInstance();extern "C" void Zone3D_SetBMDJInstanceVisibilityFlag(int,int,int);extern "C" void GameState_SetIndexedFlagAndNotifyOverlay(int,bool);
// Original: arm9/main @ 0x020AE6E8; symbol: func_020ae6e8; size: 0x48.
extern "C" ARM void Zone3D_UpdateStateForZone2010(int value){if(*Zone3D_GetMainInstance()==0x2010){Zone3D_SetBMDJInstanceVisibilityFlag(value,0,2);GameState_SetIndexedFlagAndNotifyOverlay(0,value==0);}}
