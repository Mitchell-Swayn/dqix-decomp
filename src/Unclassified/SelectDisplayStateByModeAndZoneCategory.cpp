#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <World/ZonePredicates.h>
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();extern "C" void Object_TransitionByte9C1AndResetLoadState(void*,int);
// Original: arm9/main @ 0x020DC214; symbol: func_020dc214; size: 0xA8.
extern "C" void SelectDisplayStateByModeAndZoneCategory(int mode) {unsigned zone;void* object=*(void**)((char*)GameResources_GetInstance()+0x36d0);zone=*ReadGlobalValueAt020FB3F0();if(mode==1){Object_TransitionByte9C1AndResetLoadState(object,1);return;}if(mode==2){Object_TransitionByte9C1AndResetLoadState(object,4);return;}if(mode!=0)return;if(IsGrottoZone(zone)){Object_TransitionByte9C1AndResetLoadState(object,3);return;}if(zone==10000 || zone==10100){Object_TransitionByte9C1AndResetLoadState(object,4);return;}Object_TransitionByte9C1AndResetLoadState(object,0);}
