#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
#include "Combat/Overlay_0/GetCombatantByID.h"
// Original data: arm9/ov024 @ 0x21fec1c; symbol: data_ov024_021fec1c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Fields{signed f0:3,f1:3,rest:26;};struct Seed{short ids[4];};extern Seed CombatSelectTargetsWithoutAilmentOrPrimaryStatusBit5_UnknownRoleInitializedBytes;extern "C" int Combat_TryGetLinkedLivingTargetId(void*,unsigned,short*),Combat_CollectEligiblePartyIds(void*,short*,int,int),CombatEffect_TargetHasConfusion(unsigned char*);extern "C" bool CombatStatus_HasSleep(unsigned*);extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*,unsigned,void*,int*,short*);
// Original: arm9/ov024 @ 0x021F1B40; symbol: func_ov024_021f1b40; size: 0x124.
extern "C" ARM int Combat_SelectTargetsWithoutAilmentOrPrimaryStatusBit5(void*self,unsigned source,void*descriptor,int*count,short*out){Seed seed=CombatSelectTargetsWithoutAilmentOrPrimaryStatusBit5_UnknownRoleInitializedBytes;int total=Combat_TryGetLinkedLivingTargetId(self,source,seed.ids);if(total<=0){total=Combat_CollectEligiblePartyIds(*(void**)self,seed.ids,4,1);if(total<=0)return 0;}*count=0;for(int i=0;i<total;i++){GameObject*object=GetCombatantByID(*(int*)self,seed.ids[i]);if(object){unsigned char*data=P(object,0x138);if(!CombatStatus_HasSleep((unsigned*)data)&&!CombatEffect_TargetHasConfusion((unsigned char*)object)){int at=(*count)++;out[at]=seed.ids[i];}}}if(*count<=0)return 0;Combat_SelectWeightedTargetCountFromPackedMode(self,source,descriptor,count,out);return 1;}