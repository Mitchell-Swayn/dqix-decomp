#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _Z16GetCombatantByIDii(int,int);extern "C" void ClearCombatantStatusGroupsApplyBuffsAndDispatchRecords(char*,int,int);extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);extern "C" void* GameState_CreateAndAppendIndexedRecord(void*,unsigned);extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned,unsigned,int);
// Original: arm9/ov024 @ 0x021E3CEC; symbol: SetCombatantModeAndDispatchMask40; size: 0x9c.
extern "C" unsigned long long Combat_ResetStatusGroupsAndQueueResetResult(char* self,int unused,int id){
void* target=_Z16GetCombatantByIDii(W(self,16),id);if(!target)return 0;ClearCombatantStatusGroupsApplyBuffsAndDispatchRecords(self,id,1);unsigned long long mask=0;Combat_SetResultMaskFlag(P(self,16),&mask,40);void* record=GameState_CreateAndAppendIndexedRecord(self,0);if(record)Combat_PopulateResultWithCurrentHealthAndMagic(P(self,16),record,target,0,(unsigned)mask,(unsigned)(mask>>32),0);return 0;
}
