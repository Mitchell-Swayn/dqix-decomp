#include <globaldefs.h>
ARM
extern "C" float Combat_GetCurrentHealthFraction(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int _fgr(...);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov024 @ 0x21feefc; symbol: data_ov024_021feefc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char BattleAISelectActorWhenOtherEnemyHpAtMostEightPercent_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021F3D78; symbol: SelectExcludedIdWhenLowRatioPeerExists.
extern "C" int BattleAI_SelectActorWhenOtherEnemyHpAtMostEightPercent(char*self,int excluded,int unused,int*count,short*output){
struct Ids{short values[8];};Ids ids=*(Ids*)BattleAISelectActorWhenOtherEnemyHpAtMostEightPercent_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags(W(self,0),ids.values,8,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;i++){if(excluded==ids.values[i])continue;char*object=C(_Z16GetCombatantByIDii(W(self,0),ids.values[i]));if(object){float ratio=Combat_GetCurrentHealthFraction(object);if(ratio>0.08f)continue;output[(*count)++]=ids.values[i];}}if(*count<=0)return 0;*count=1;output[0]=excluded;return 1;
}
