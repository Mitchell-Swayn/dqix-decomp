#include <globaldefs.h>
ARM
extern "C" void* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_ClearNegativeStatusesAndReapplyBuffs(char*,int);
extern "C" void* GameState_CreateAndAppendIndexedRecord(char*,int);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(int,void*,void*,int,int,int,int);
// Original: arm9/ov024 @ 0x021E40D8; symbol: DispatchCombatantEvent203; size: 0x80.
// Dispatches event 203 to an existing combatant when its eligibility helper is positive.
extern "C" unsigned long long Combat_ClearNegativeStatusesAndQueueRecoveryResult(char* self,int unused,int id) {
 void* target=_Z16GetCombatantByIDii(*(int*)(self+16),id);if(!target)return 0;
 if(Combat_ClearNegativeStatusesAndReapplyBuffs(self,id)>0){void* event=GameState_CreateAndAppendIndexedRecord(self,203);if(event)Combat_PopulateResultWithCurrentHealthAndMagic(*(int*)(self+16),event,target,0,0,0,0);}
 return 0;
}
