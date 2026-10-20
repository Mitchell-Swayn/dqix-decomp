#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int CombatEffect_TargetHasParalysis(void*);
extern "C" void CombatStatus_ClearParalysis(void*);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* GameState_CreateAndAppendIndexedRecord(void*,unsigned);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,int,int,int);
// Original: arm9/ov024 @ 0x021E32F4; symbol: ClearLinkedFlagAndBuildCombatantMask; size: 0xb0.
// For linked flag8 combatant, clears operation fields, sets output mask bit26 and creates record505.
extern "C" unsigned long long Combat_ClearParalysisAndQueueResult(char* p,int unused,int index){
 char* combatant=_Z16GetCombatantByIDii(U(p,16),index);if(!combatant)return 0;unsigned long long mask=0;
 if(CombatEffect_TargetHasParalysis(combatant)){CombatStatus_ClearParalysis((void*)U(combatant,0x138));Combat_SetResultMaskFlag((void*)U(p,16),&mask,26);char* state=(char*)U(combatant,0x138);B(state,0x3b)=(B(state,0x3b)&~1)|1;void* record=GameState_CreateAndAppendIndexedRecord(p,505);if(record)Combat_PopulateResultWithCurrentHealthAndMagic((void*)U(p,16),record,combatant,0,0,0,0);}
 return mask;
}
