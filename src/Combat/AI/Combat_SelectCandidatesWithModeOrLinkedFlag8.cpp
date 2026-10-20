#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int CombatEffect_TargetHasParalysis(LinkedDescriptorView*);
struct Record;struct A;
extern "C" int CombatStatus_HasAilmentModeOne(Record*);
extern "C" int CombatStatus_HasAilmentModeTwo(A*);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*,unsigned,void*,int*,short*);
extern "C" int Combat_TryGetLinkedLivingTargetId(void*,int,short*);
// Original data: arm9/ov024 @ 0x21fec24; symbol: data_ov024_021fec24.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Ids{short values[4];};extern "C" Ids CombatSelectCandidatesWithModeOrLinkedFlag8_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F1A0C; symbol: func_ov024_021f1a0c; size: 0x134.
// Filters candidates passing either mode predicate or linked flag8, then applies weighted target-count selection.
extern "C" int Combat_SelectCandidatesWithModeOrLinkedFlag8(int* self,int source,void* descriptor,int* result,short* output){
 Ids ids=CombatSelectCandidatesWithModeOrLinkedFlag8_UnknownRoleInitializedBytes;int count=Combat_TryGetLinkedLivingTargetId(self,source,ids.values);
 if(count<=0){count=Combat_CollectEligiblePartyIds((void*)*self,ids.values,4,1);if(count<=0)return 0;}
 *result=0;
 for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*self,ids.values[i]);if(object&&(CombatStatus_HasAilmentModeOne(*(Record**)(object+0x138))||CombatStatus_HasAilmentModeTwo(*(A**)(object+0x138))||CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object))){output[(*result)++]=ids.values[i];}}
 if(*result<=0)return 0;
 Combat_SelectWeightedTargetCountFromPackedMode(self,source,descriptor,result,output);
 return 1;
}
