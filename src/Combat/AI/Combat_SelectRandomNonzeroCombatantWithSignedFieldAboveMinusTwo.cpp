#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(int,short*,int,int);
extern "C" int Combat_CollectEligiblePartyIds(int,short*,int,int);
extern "C" int Combat_SelectRandomCandidateInPlace(void*,int*,short*);
// Original data: arm9/ov024 @ 0x21feb84; symbol: data_ov024_021feb84.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatSelectRandomNonzeroCombatantWithSignedFieldAboveMinusTwo_UnknownRoleInitializedBytes[];
struct IdList {short ids[4];};

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov024 @ 0x021F4FD8; symbol: Combat_SelectRandomNonzeroCombatantWithSignedFieldAboveMinusTwo; size: 0xF4.
extern "C" int Combat_SelectRandomNonzeroCombatantWithSignedFieldAboveMinusTwo(char* self,int unused1,int unused2,int* result,short* output){
 IdList list=*(IdList*)CombatSelectRandomNonzeroCombatantWithSignedFieldAboveMinusTwo_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(W(self,0),list.ids,4,1);if(count<=0)return 0;
 *result=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(W(self,0),list.ids[i]);if(object&&(H(P(object,0x138),12)&&((W(P(object,0x138),0x58)<<23)>>29)>-2))output[(*result)++]=list.ids[i];}
 if(*result<=0)return 0;Combat_SelectRandomCandidateInPlace(self,result,output);return 1;
}