#include <globaldefs.h>
ARM
#pragma opt_lifetimes off
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void* _Z16GetCombatantByIDii(int,int);extern "C" int Combat_ClearNegativeStatusesAndReapplyBuffs(char*,int);extern "C" void* Combat_ClearCurrentResultNodeSlot(void*);extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,int,int,int);
// Original: arm9/ov024 @ 0x021DF1E8; symbol: CreateCombatantRecordAndDispatchWithContextFlag; size: 0x9c.
extern "C" void* Combat_ClearNegativeStatusesAndBuildActionResult(char* self,int unused,int id){
void* target=_Z16GetCombatantByIDii(W(self,16),id);if(!target)return 0;if(Combat_ClearNegativeStatusesAndReapplyBuffs(self,id)>0)W(self,20)++;void* record=Combat_ClearCurrentResultNodeSlot(P(self,16));if(!record)return 0;Combat_PopulateResultWithCurrentHealthAndMagic(P(self,16),record,target,0,0,0,(((unsigned)B(P(self,12),28)<<24)>>31)!=0);return record;
}
