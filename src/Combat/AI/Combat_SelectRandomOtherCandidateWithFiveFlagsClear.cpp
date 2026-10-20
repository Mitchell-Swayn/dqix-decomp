#include <globaldefs.h>
ARM
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" bool CombatStatus_HasSleep(unsigned*);
struct LinkedDescriptorView;
extern "C" int CombatEffect_TargetHasParalysis(LinkedDescriptorView*);
extern "C" int Combat_HasActionRestriction(LinkedDescriptorView*);
extern "C" int Combat_HasSuperHighTension(void*);
extern "C" int CombatEffect_TargetHasConfusion(unsigned char*);
extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);
// Original data: arm9/ov024 @ 0x21fedec; symbol: data_ov024_021fedec.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct IdList{short ids[8];};extern "C" IdList CombatSelectRandomOtherCandidateWithFiveFlagsClear_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F36CC; symbol: func_ov024_021f36cc; size: 0x130.
// Excludes the supplied ID and five flagged categories, then selects a random remaining candidate.
extern "C" int Combat_SelectRandomOtherCandidateWithFiveFlagsClear(int* self,int excluded,int unused,int* result,short* output){
 IdList list=CombatSelectRandomOtherCandidateWithFiveFlagsClear_UnknownRoleInitializedBytes;
 int count=Combat_CollectGroupIndicesByDescriptorFlags((char*)*self,list.ids,8,1);
 if(count<=0)return 0;
 *result=0;
 for(int i=0;i<count;i++){
 if(excluded==list.ids[i])continue;
 char* object=_Z16GetCombatantByIDii(*self,list.ids[i]);
 if(object&&!CombatStatus_HasSleep(*(unsigned**)(object+0x138))&&!CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object)&&!CombatEffect_TargetHasConfusion((unsigned char*)object)&&!Combat_HasActionRestriction((LinkedDescriptorView*)object)&&!Combat_HasSuperHighTension(object))output[(*result)++]=list.ids[i];
 }
 if(*result<=0)return 0;
 Combat_SelectRandomCandidateInPlace((void**)self,result,output);return 1;
}
