#include <globaldefs.h>
#include <World/ZoneFeatures.h>
extern "C" char* ReadGlobalValueAt020FB3F0();
extern "C" void Zone3D_SetBMDJInstanceVisibilityFlag(int,unsigned,unsigned);
extern "C" void GameState_SetIndexedFlagAndNotifyOverlay(unsigned,bool);
// Original: arm9/main @ 0x020AE730; symbol: func_020ae730; size: 0xA4.
extern "C" void UpdateTwoZoneOpcode6AEntriesForZone1EDD(int flag) {if(*(unsigned short*)ReadGlobalValueAt020FB3F0()!=0x1edd)return;char* zone=ReadGlobalValueAt020FB3F0();ZoneFeatures* features=(ZoneFeatures*)(zone+0x6c);void* first=features->GetOpcode6aEntry(3);void* second=features->GetOpcode6aEntry(4);if(!first||!second)return;unsigned* a=(unsigned*)((char*)first+0x28);unsigned* b=(unsigned*)((char*)second+0x28);if(flag){*a&=~8;*b&=~8;}else{*a|=8;*b|=8;}Zone3D_SetBMDJInstanceVisibilityFlag(flag,0,16);GameState_SetIndexedFlagAndNotifyOverlay(6,flag!=0);}
