#include <globaldefs.h>
ARM
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" float Combat_GetCurrentHealthFraction(...);
extern "C" int Combat_FindIndexedMonsterObject(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov024 @ 0x21fee2c; symbol: data_ov024_021fee2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char BattleAISelectHealthyActorWhenThirdOfEnemiesBelowHalfHp_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021F38F0; symbol: SelectLowRatioCombatantsWhenAtLeastOneThirdQualify.
extern "C" int BattleAI_SelectHealthyActorWhenThirdOfEnemiesBelowHalfHp(char*self,int index,int unused,int*count,short*output){
int object=Combat_FindIndexedMonsterObject(P(self,0),index);if(!object)return 0;if(Combat_GetCurrentHealthFraction(object)<0.5f)return 0;struct Slots{short data[8];};Slots slots=*(Slots*)BattleAISelectHealthyActorWhenThirdOfEnemiesBelowHalfHp_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags(P(self,0),slots.data,8,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;i++){if(index==slots.data[i])continue;int actor=_Z16GetCombatantByIDii(P(self,0),slots.data[i]);if(!actor)continue;if(Combat_GetCurrentHealthFraction(actor)>=0.5f)continue;output[(*count)++]=slots.data[i];}if(*count*3<total)return 0;*count=1;output[0]=index;return 1;
}
