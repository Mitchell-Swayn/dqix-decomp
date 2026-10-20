#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov024 @ 0x21fee6c; symbol: data_ov024_021fee6c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Eight{short values[8];};extern "C" {unsigned char* Combat_FindIndexedMonsterObject(void*,int);float Combat_GetCurrentHealthFraction(unsigned char*);int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);unsigned char* _Z16GetCombatantByIDii(int,int);int Combat_SelectRandomCandidateInPlace(void**,int*,short*);extern Eight BattleAISelectRandomOtherEnemyWithMissingHp_UnknownRoleInitializedBytes;}
// Original: arm9/ov024 @0x021f3b20; symbol:Combat_SelectRandomOtherCombatantBelowFullRatio; size:0x11c.
// Selects random different combatant below full halfword ratio when requested descriptor quantity exceeds one.
extern "C" int BattleAI_SelectRandomOtherEnemyWithMissingHp(unsigned char* self,int id,int unused,int* count,short* output){unsigned char* selected=Combat_FindIndexedMonsterObject(P(self,0),id);if(!selected)return 0;if(U(P(selected,0x138),0)<=1)return 0;Eight candidates=BattleAISelectRandomOtherEnemyWithMissingHp_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags((char*)P(self,0),candidates.values,8,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;++i){if(id==candidates.values[i])continue;unsigned char* object=_Z16GetCombatantByIDii(W(self,0),candidates.values[i]);if(!object)continue;if(Combat_GetCurrentHealthFraction(object)>=1.0f)continue;int next=*count;*count=next+1;output[next]=candidates.values[i];}if(*count<=0)return 0;Combat_SelectRandomCandidateInPlace((void**)self,count,output);return 1;}
