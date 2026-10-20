#include <globaldefs.h>
ARM
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);
extern "C" bool Combat_TestPartyFlagsAndUnrestrictedDescriptor(int*,int);
extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov024 @ 0x21fee5c; symbol: data_ov024_021fee5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff00000000000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct IdList{short ids[8];};extern "C" IdList CombatSelectLowStatusGroupCandidateAfterPartyGate_UnknownRoleInitializedBytes;
struct StatusFields {unsigned low:18;signed status:3;unsigned high:11;};
// Original: arm9/ov024 @ 0x021F0A20; symbol: func_ov024_021f0a20; size: 0x164.
// Requires a party member passing flag gates, then selects a group candidate with packed status field six below two.
extern "C" int Combat_SelectLowStatusGroupCandidateAfterPartyGate(int* self,int unused1,int unused2,int* result,short* output){
 int found=0;IdList list=CombatSelectLowStatusGroupCandidateAfterPartyGate_UnknownRoleInitializedBytes;
 int count=Combat_CollectEligiblePartyIds((void*)*self,list.ids,4,1);if(count<=0)return 0;
 for(int i=0;i<count;i++){if(Combat_TestPartyFlagsAndUnrestrictedDescriptor(self,list.ids[i])){found=1;break;}}
 if(!found)return 0;
 memset(list.ids,-1,16);
 count=Combat_CollectGroupIndicesByDescriptorFlags((char*)*self,list.ids,8,1);if(count<=0)return 0;
 *result=0;for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*self,list.ids[i]);if(object&&((StatusFields*)(*(char**)(object+0x138)+0x58))->status<2)output[(*result)++]=list.ids[i];}
 if(*result<=0)return 0;Combat_SelectRandomCandidateInPlace((void**)self,result,output);return 1;
}
