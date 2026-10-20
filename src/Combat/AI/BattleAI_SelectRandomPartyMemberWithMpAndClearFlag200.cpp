#include <globaldefs.h>
ARM
extern "C" int Combat_SelectRandomCandidateInPlace(...);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov024 @ 0x21fec4c; symbol: data_ov024_021fec4c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char BattleAISelectRandomPartyMemberWithMpAndClearFlag200_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021F567C; symbol: SelectRandomLivingUnflaggedCombatant.
extern "C" int BattleAI_SelectRandomPartyMemberWithMpAndClearFlag200(char*self,int unused,int unused2,int*count,short*output){
struct Ids{short values[4];};Ids ids=*(Ids*)BattleAISelectRandomPartyMemberWithMpAndClearFlag200_UnknownRoleInitializedBytes;int total=Combat_CollectEligiblePartyIds(W(self,0),ids.values,4,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;i++){char*object=C(_Z16GetCombatantByIDii(W(self,0),ids.values[i]));if(object&&H(P(object,0x138),2)!=0&&!Combatant_TestPrimaryStatusFlagBit9(object))output[(*count)++]=ids.values[i];}if(*count<=0)return 0;Combat_SelectRandomCandidateInPlace(self,count,output);return 1;
}
