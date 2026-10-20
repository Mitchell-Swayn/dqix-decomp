#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int CombatEffect_TargetHasParalysis(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*,unsigned,void*,int*,short*);
extern "C" int Combat_TryGetLinkedLivingTargetId(void*,int,short*);
// Original data: arm9/ov024 @ 0x21feb3c; symbol: data_ov024_021feb3c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Ids{short values[4];};extern "C" Ids CombatSelectAtLeastTwoCandidatesWithFlags8And200Clear_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021EE574; symbol: func_ov024_021ee574; size: 0x134.
// Filters flag8/200 candidates, requires two eligible IDs, then applies weighted target-count selection.
extern "C" int Combat_SelectAtLeastTwoCandidatesWithFlags8And200Clear(int* self,int source,void* descriptor,int* result,short* output){
 Ids ids=CombatSelectAtLeastTwoCandidatesWithFlags8And200Clear_UnknownRoleInitializedBytes;int count=Combat_TryGetLinkedLivingTargetId(self,source,ids.values);
 if(count<=0){count=Combat_CollectEligiblePartyIds((void*)*self,ids.values,4,1);if(count<=0)return 0;}
 *result=0;
 for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*self,ids.values[i]);if(object&&!CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object)&&!Combatant_TestPrimaryStatusFlagBit9(object)){output[*result]=ids.values[i];++*result;}}
 if(*result<2){*result=0;return 0;}
 Combat_SelectWeightedTargetCountFromPackedMode(self,source,descriptor,result,output);
 return output[0]>=0;
}
