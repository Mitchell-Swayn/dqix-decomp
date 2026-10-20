#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
#include "Combat/Overlay_0/GetCombatantByID.h"
// Original data: arm9/ov024 @ 0x21feba4; symbol: data_ov024_021feba4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct LinkedDescriptorView;extern short BattleAICopyPartyWhenTwoThirdsPassLinkedFlagCounterAt4E_UnknownRoleInitializedBytes[];extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int),CombatEffect_TargetHasParalysis(LinkedDescriptorView*);extern "C" bool Combat_TestFlaggedCandidatesBelowOneThird(int*);
// Original: arm9/ov024 @ 0x021F4D6C; symbol: func_ov024_021f4d6c; size: 0x118.
extern "C" ARM int BattleAI_CopyPartyWhenTwoThirdsPassLinkedFlagCounterAt4E(int*self,int unused1,int unused2,int*count,short*out){struct Seed{short ids[4];};Seed seed=*(const Seed*)BattleAICopyPartyWhenTwoThirdsPassLinkedFlagCounterAt4E_UnknownRoleInitializedBytes;int total=Combat_CollectEligiblePartyIds((void*)*self,seed.ids,4,1);if(total<=0)return 0;if(!Combat_TestFlaggedCandidatesBelowOneThird(self))return 0;*count=0;for(int i=0;i<total;i++){GameObject*object=GetCombatantByID(*self,seed.ids[i]);if(object&&!CombatEffect_TargetHasParalysis((LinkedDescriptorView*)object)){int amount=P(object,0x138)[0x4e];if(amount>0){int at=(*count)++;out[at]=seed.ids[i];}}}if(*count<=0)return 0;if(*count*3<total*2)return 0;*count=total;memcpy(out,seed.ids,8);return 1;}