#include <globaldefs.h>
ARM
struct LinkedDescriptorView;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int CombatEffect_TargetHasDazzle(void*);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*,unsigned,void*,int*,short*);
extern "C" int Combat_TryGetLinkedLivingTargetId(void*,int,short*);
// Original data: arm9/ov024 @ 0x21feb2c; symbol: data_ov024_021feb2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Ids{short values[4];};extern "C" Ids CombatSelectCandidatesBelowTwiceSourceHalfword8_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021EDFA0; symbol: func_ov024_021edfa0; size: 0x150.
// Rejects flag40 source objects and selects targets whose nested halfword10 is below twice the source halfword8.
extern "C" int Combat_SelectCandidatesBelowTwiceSourceHalfword8(int* self,int source,void* descriptor,int* result,short* output){
 char* original=_Z16GetCombatantByIDii(*self,source);if(!original)return 0;if(CombatEffect_TargetHasDazzle(original))return 0;
 Ids ids=CombatSelectCandidatesBelowTwiceSourceHalfword8_UnknownRoleInitializedBytes;int count=Combat_TryGetLinkedLivingTargetId(self,source,ids.values);
 if(count<=0){count=Combat_CollectEligiblePartyIds((void*)*self,ids.values,4,1);if(count<=0)return 0;}
 *result=0;
 for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*self,ids.values[i]);if(!object)continue;int sourceValue=*(unsigned short*)(*(char**)(original+0x138)+8);int targetValue=*(unsigned short*)(*(char**)(object+0x138)+10);if(sourceValue*2>targetValue){output[*result]=ids.values[i];++*result;}}
 if(*result<=0)return 0;
 Combat_SelectWeightedTargetCountFromPackedMode(self,source,descriptor,result,output);
 return output[0]>=0;
}
