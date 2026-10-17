#include <globaldefs.h>
#include <World/Zone3D.h>
extern "C" Zone3D* ReadGlobalValueAt020FB3F0();extern "C" int IsCurrentResourceRecordTypeFour();extern "C" void GameState_SetIndexedFlagAndNotifyOverlay(int,bool);
// Original: arm9/main @ 0x020AE7D4; symbol: func_020ae7d4; size: 0xAC.
extern "C" ARM void Zone3D_ToggleTwoBMDJInstancesInZone1BBD(int enabled){Zone3D* zone=ReadGlobalValueAt020FB3F0();if(*(unsigned short*)zone!=0x1bbd)return;unsigned short* a=(unsigned short*)zone->FindBMDJInstance(0,13);unsigned short* b=(unsigned short*)zone->FindBMDJInstance(0,15);if(!a||!b)return;if(!IsCurrentResourceRecordTypeFour()){if(!enabled){a[1]&=~4;b[1]|=4;}else{a[1]|=4;b[1]&=~4;}}GameState_SetIndexedFlagAndNotifyOverlay(9,enabled!=0);}
