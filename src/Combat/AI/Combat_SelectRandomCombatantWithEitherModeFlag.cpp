#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(int,short*,int,int);
extern "C" int Combat_CollectEligiblePartyIds(int,short*,int,int);
extern "C" int Combat_SelectRandomCandidateInPlace(void*,int*,short*);
// Original data: arm9/ov024 @ 0x21fec7c; symbol: data_ov024_021fec7c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatSelectRandomCombatantWithEitherModeFlag_UnknownRoleInitializedBytes[];
struct IdList {short ids[8];};
extern "C" int CombatStatus_HasAilmentModeOne(void*);
extern "C" int CombatStatus_HasAilmentModeTwo(void*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov024 @ 0x021F4880; symbol: Combat_SelectRandomCombatantWithEitherModeFlag; size: 0xF4.
extern "C" int Combat_SelectRandomCombatantWithEitherModeFlag(char* self,int unused1,int unused2,int* result,short* output){
 IdList list=*(IdList*)CombatSelectRandomCombatantWithEitherModeFlag_UnknownRoleInitializedBytes;int count=Combat_CollectGroupIndicesByDescriptorFlags(W(self,0),list.ids,8,1);if(count<=0)return 0;
 *result=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(W(self,0),list.ids[i]);if(object&&(CombatStatus_HasAilmentModeOne(P(object,0x138))||CombatStatus_HasAilmentModeTwo(P(object,0x138))))output[(*result)++]=list.ids[i];}
 if(*result<=0)return 0;Combat_SelectRandomCandidateInPlace(self,result,output);return 1;
}