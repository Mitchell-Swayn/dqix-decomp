#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov024 @ 0x21fee3c; symbol: data_ov024_021fee3c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Eight{short values[8];};extern "C" {unsigned char* Combat_FindIndexedMonsterObject(void*,int);float Combat_GetCurrentHealthFraction(unsigned char*);int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);unsigned char* _Z16GetCombatantByIDii(int,int);extern Eight BattleAISelectHealthyActorWhenHalfOfEnemiesNeedHpSupport_UnknownRoleInitializedBytes;}
// Original: arm9/ov024 @0x021f3a04; symbol:Combat_SelectRequestedIdWhenHalfOfOthersBelowRatio; size:0x11c.
// Selects requested combatant when its ratio is at least half and at least half of others meet lower-ratio and descriptor tests.
extern "C" int BattleAI_SelectHealthyActorWhenHalfOfEnemiesNeedHpSupport(unsigned char* self,int id,int unused,int* count,short* output){unsigned char* selected=Combat_FindIndexedMonsterObject(P(self,0),id);if(!selected)return 0;if(Combat_GetCurrentHealthFraction(selected)<0.5f)return 0;Eight candidates=BattleAISelectHealthyActorWhenHalfOfEnemiesNeedHpSupport_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags((char*)P(self,0),candidates.values,8,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;++i){if(id==candidates.values[i])continue;unsigned char* object=_Z16GetCombatantByIDii(W(self,0),candidates.values[i]);if(!object)continue;if(Combat_GetCurrentHealthFraction(object)>=0.5f||H(P(object,0x138),0x2c)>0)continue;int next=*count;*count=next+1;output[next]=candidates.values[i];}if(total>(*count<<1))return 0;*count=1;*output=id;return 1;}
