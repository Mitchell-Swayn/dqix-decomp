#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21feb04; symbol: data_ov024_021feb04.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000ffffffff00000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char* _Z16GetCombatantByIDii(void*,int);extern "C" void* memcpy(void*,const void*,unsigned);extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);extern "C" int CombatStatus_HasSleep(void*);struct IDs{short values[4];};extern "C" IDs BattleAICopyPartyWhenRecoverableAilmentGateAllows_UnknownRoleInitializedBytes;extern "C" int Combat_TestFlaggedCandidatesBelowOneThird(void*);
// Original: arm9/ov024 @ 0x021F6424; symbol: CopyCollectedMembersWhenAnyLinkedMaskClear; size: 0xDC.
extern "C" int BattleAI_CopyPartyWhenRecoverableAilmentGateAllows(void** self,int unused,int unused2,int* countOut,void* out){IDs ids=BattleAICopyPartyWhenRecoverableAilmentGateAllows_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,ids.values,4,1);if(count<=0)return 0;if(!Combat_TestFlaggedCandidatesBelowOneThird(self))return 0;int found=0;for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*self,ids.values[i]);if(object&&!CombatStatus_HasSleep(P(object,0x138))){found=1;break;}}if(!found)return 0;*countOut=count;memcpy(out,&ids,8);return 1;}
