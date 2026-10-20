#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);extern "C" int _ZNK8Object3D9GetRadiusEv(void*);extern "C" int GetMaximumPriorityForAvailableCombatantSlot(void*,int);
// Original: arm9/ov000 @ 0x02167C28; symbol: AssignCombatantToFirstRadiusCompatibleSlot; size: 0xAC.
// Clears an existing indexed slot and assigns the combatant to the first slot with adequate radius.
extern "C" int AssignCombatantToFirstRadiusCompatibleSlot(char* self,int id){void* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),id);if(!object)return -1;for(int i=0;i<8;i++){int* entries=(int*)(*(char**)(self+0x29c)+0x8de0);unsigned value=(unsigned)entries[i]&255;
if(value==(unsigned)id){entries[i]=-1;break;}}int radius=_ZNK8Object3D9GetRadiusEv(object);for(int i=0;i<8;i++){if(GetMaximumPriorityForAvailableCombatantSlot(self,i)>=radius){*(int*)(*(char**)(self+0x29c)+i*4+0x8de0)=id;return i;}}return -1;}
