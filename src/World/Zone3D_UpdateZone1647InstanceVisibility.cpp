#include <globaldefs.h>
extern "C" unsigned short* Zone3D_GetMainInstance();extern "C" void Zone3D_SetBMDJInstanceVisibilityFlag(int,int,int);extern "C" void GameState_SetIndexedFlagAndNotifyOverlay(int,bool);
#pragma optimization_level 4
// Original: arm9/main @ 0x020AE990; symbol: func_020ae990; size: 0x60.
extern "C" ARM void Zone3D_UpdateZone1647InstanceVisibility(int flag){if(*Zone3D_GetMainInstance()!=0x1647)return;if(!flag)Zone3D_SetBMDJInstanceVisibilityFlag(1,0,4);else Zone3D_SetBMDJInstanceVisibilityFlag(0,0,4);GameState_SetIndexedFlagAndNotifyOverlay(46,flag!=0);}
