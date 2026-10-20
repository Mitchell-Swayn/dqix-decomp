#include <globaldefs.h>
ARM
// Original data: arm9/ov024 @ 0x21fea34; symbol: data_ov024_021fea34.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Ids{short values[4];};extern "C" {extern Ids CombatCopyPartyIdsWhenAnyLacksPrimaryStatusBit5_UnknownRoleInitializedBytes;int Combat_CollectEligiblePartyIds(void*,short*,int,int);void* _Z16GetCombatantByIDii(void*,int);int CombatEffect_TargetHasConfusion(void*);void* memcpy(void*,const void*,unsigned);}
// Original: arm9/ov024 @ 0x021F0578; symbol: CopyPartyIdsWhenAnyDescriptorLacksFlag20; size: 0xc4.
// Copies initialized party ID slots when any present combatant lacks required descriptor flag.
extern "C" int Combat_CopyPartyIdsWhenAnyLacksPrimaryStatusBit5(void** self,int a,int b,int* count,void* output){Ids local=CombatCopyPartyIdsWhenAnyLacksPrimaryStatusBit5_UnknownRoleInitializedBytes;int n=Combat_CollectEligiblePartyIds(*self,local.values,4,1);if(n<=0)return 0;int found=0;for(int i=0;i<n;++i){void* obj=_Z16GetCombatantByIDii(*self,local.values[i]);if(obj&&!CombatEffect_TargetHasConfusion(obj)){found=1;break;}}if(!found)return 0;*count=n;memcpy(output,local.values,8);return 1;}
