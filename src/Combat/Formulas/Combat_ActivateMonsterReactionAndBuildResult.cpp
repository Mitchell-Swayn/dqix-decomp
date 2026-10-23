#include <globaldefs.h>
ARM
extern "C" int CombatantState_IsEligibleForLinkedCombatEffect(...);
extern "C" int Combat_ClearCurrentResultNodeSlot(...);
extern "C" int Combat_FindIndexedMonsterObject(...);
extern "C" int CombatantState_ActivateLinkedCombatEffect(...);
extern "C" int GameObject_SetCombatActivationMarker(...);
extern "C" int _Z17NextRandomBetweenP6Randomii(...);
extern "C" void Combat_QueueForcedTargetReaction(void*,int);
extern "C" int Combat_PopulateResultWithCurrentHealthAndMagic(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021E1DE8; symbol: CreateIndexedActiveRecordWithRandomByte.
extern "C" int Combat_ActivateMonsterReactionAndBuildResult(char*self,int value,int index){
char*object=C(Combat_FindIndexedMonsterObject(P(self,16),index));if(!object)return 0;char*record=P(object,0x148);if(!record)return 0;if(CombatantState_IsEligibleForLinkedCombatEffect(P(object,0x138))){int n=_Z17NextRandomBetweenP6Randomii(P(self,16),B(record,40),B(record,41));if(n>0){CombatantState_ActivateLinkedCombatEffect(P(object,0x138),(unsigned char)n);GameObject_SetCombatActivationMarker(object,1);H(P(object,0x138),46)=value;Combat_QueueForcedTargetReaction(P(self,16),index);}}int current=Combat_ClearCurrentResultNodeSlot(P(self,16));if(!current)return 0;struct Flag{unsigned char pad:7;unsigned char enabled:1;};int bit=((Flag*)(P(self,12)+28))->enabled?1:0;Combat_PopulateResultWithCurrentHealthAndMagic(P(self,16),current,object,0,0,0,bit);return current;
}
