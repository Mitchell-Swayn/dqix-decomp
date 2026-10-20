#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21fee4c; symbol: data_ov024_021fee4c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char* _Z16GetCombatantByIDii(void*,int);extern "C" void* memcpy(void*,const void*,unsigned);extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);extern "C" int CombatStatus_HasSleep(void*);struct IDs{short values[8];};extern "C" IDs BattleAISelectActorWhenEightGroupMembersLackRecoverableAilment_UnknownRoleInitializedBytes;extern "C" char* Combat_FindIndexedMonsterObject(void*,int);extern "C" int Combat_CollectEligibleIndicesInEnemyGroup(void*,short*,int,unsigned char,int);
// Original: arm9/ov024 @ 0x021F5344; symbol: TestEightCollectedObjectsHaveLinkedMaskClear; size: 0xDC.
extern "C" int BattleAI_SelectActorWhenEightGroupMembersLackRecoverableAilment(void** self,int index,int unused,int* countOut,short* out){char* object=Combat_FindIndexedMonsterObject(*self,index);if(!object)return 0;int group=B(object,0x17c);if(group>=3)return 0;IDs ids=BattleAISelectActorWhenEightGroupMembersLackRecoverableAilment_UnknownRoleInitializedBytes;int count=Combat_CollectEligibleIndicesInEnemyGroup(*self,ids.values,8,(unsigned char)group,1);int valid=0;for(int i=0;i<count;i++){char* entry=_Z16GetCombatantByIDii(*self,ids.values[i]);if(entry&&!CombatStatus_HasSleep(P(entry,0x138)))valid++;}if(valid!=8)return 0;*countOut=1;*out=index;return 1;}
