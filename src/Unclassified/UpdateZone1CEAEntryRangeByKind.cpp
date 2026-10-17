#include <globaldefs.h>
ARM
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();extern "C" void Zone3D_SetBMDJInstanceVisibilityFlag(unsigned char,int,unsigned short);extern "C" void GameState_SetIndexedFlagAndNotifyOverlay(int,bool);
// Original: arm9/main @ 0x020AEE04; symbol: func_020aee04; size: 0xC4.
extern "C" void UpdateZone1CEAEntryRangeByKind(int kind,unsigned flag){if(*ReadGlobalValueAt020FB3F0()!=0x1cea)return;if(kind==1){for(int i=78;i<=88;++i)Zone3D_SetBMDJInstanceVisibilityFlag(flag,0,i);GameState_SetIndexedFlagAndNotifyOverlay(71,flag!=0);return;}if(kind==0){for(int i=55;i<=75;++i)Zone3D_SetBMDJInstanceVisibilityFlag(flag,0,i);GameState_SetIndexedFlagAndNotifyOverlay(72,flag!=0);}}
