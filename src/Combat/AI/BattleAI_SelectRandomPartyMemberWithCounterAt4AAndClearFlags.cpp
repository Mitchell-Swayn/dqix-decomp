#include <globaldefs.h>
ARM
#pragma always_inline on
inline int ReadDescriptorQuantity(unsigned char* p){return p[0x4a];}
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov024 @ 0x21feb24; symbol: data_ov024_021feb24.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct IDs{short values[4];};extern "C" {unsigned char* _Z16GetCombatantByIDii(int,int);int Combat_CollectGroupIndicesByDescriptorFlags(void*,short*,int,int);int Combat_CollectEligiblePartyIds(void*,short*,int,int);int Combat_SelectRandomCandidateInPlace(void**,int*,short*);int Combatant_TestPrimaryStatusFlagBit9(void*);int CombatStatus_HasAilmentModeOne(void*);int CombatStatus_HasAilmentModeTwo(void*);int CombatEffect_TargetHasConfusion(void*);extern IDs BattleAISelectRandomPartyMemberWithCounterAt4AAndClearFlags_UnknownRoleInitializedBytes;}
// Original: arm9/ov024 @ 0x021F5F6C; symbol: Combat_SelectRandomAvailableFlag20Target; size: 0x100.
// Filters present combatant IDs using observed descriptor fields and selects one eligible ID.
extern "C" int BattleAI_SelectRandomPartyMemberWithCounterAt4AAndClearFlags(unsigned char* self,int unused1,int unused2,int* count,short* output){IDs ids=BattleAISelectRandomPartyMemberWithCounterAt4AAndClearFlags_UnknownRoleInitializedBytes;int total=Combat_CollectEligiblePartyIds(P(self,0),ids.values,4,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;++i){unsigned char* combatant=_Z16GetCombatantByIDii(W(self,0),ids.values[i]);if(!combatant)continue;if(CombatEffect_TargetHasConfusion(combatant)||Combatant_TestPrimaryStatusFlagBit9(combatant)||ReadDescriptorQuantity(P(combatant,0x138))<=0)continue;int next=*count;*count=next+1;output[next]=ids.values[i];}if(*count<=0)return 0;Combat_SelectRandomCandidateInPlace((void**)self,count,output);return 1;}
