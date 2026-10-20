#include <globaldefs.h>
ARM
struct State{unsigned low:6;signed value:3;unsigned high:23;};struct Nested{char pad[0x51];unsigned char value;int Value(){return value;}};
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*,unsigned,void*,int*,short*);
extern "C" int Combat_TryGetLinkedLivingTargetId(void*,int,short*);
// Original data: arm9/ov024 @ 0x21feb94; symbol: data_ov024_021feb94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Ids{short values[4];};extern "C" Ids CombatSelectPositiveByte51CandidatesWithValidStatus_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021EFDFC; symbol: func_ov024_021efdfc; size: 0x140.
// Requires nested halfword12, signed status field two above minus two, clear flag200 and positive byte51 before weighted selection.
extern "C" int Combat_SelectPositiveByte51CandidatesWithValidStatus(int* self,int source,void* descriptor,int* result,short* output){
 Ids ids=CombatSelectPositiveByte51CandidatesWithValidStatus_UnknownRoleInitializedBytes;int count=Combat_TryGetLinkedLivingTargetId(self,source,ids.values);
 if(count<=0){count=Combat_CollectEligiblePartyIds((void*)*self,ids.values,4,1);if(count<=0)return 0;}
 *result=0;
 for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*self,ids.values[i]);if(object&&*(unsigned short*)(*(char**)(object+0x138)+12)&&((State*)(*(char**)(object+0x138)+0x58))->value>-2&&!Combatant_TestPrimaryStatusFlagBit9(object)&&((Nested*)*(char**)(object+0x138))->Value()>0){output[(*result)++]=ids.values[i];}}
 if(*result<=0)return 0;
 Combat_SelectWeightedTargetCountFromPackedMode(self,source,descriptor,result,output);
 return 1;
}
