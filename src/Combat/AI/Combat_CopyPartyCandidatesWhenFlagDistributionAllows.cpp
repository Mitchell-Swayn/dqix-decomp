#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" int Combat_TestFlaggedCandidatesBelowOneThird(...);
extern "C" int CombatEffect_TargetHasParalysis(...);
extern "C" void memcpy(...);
// Original data: arm9/ov024 @ 0x21febb4; symbol: data_ov024_021febb4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Four;extern "C" Four CombatCopyPartyCandidatesWhenFlagDistributionAllows_UnknownRoleInitializedBytes;
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};struct Vec {int x,y,z;};
// Original: arm9/ov024 @ 0x021F4C8C; symbol: Combat_CopyPartyCandidatesWhenFlagDistributionAllows; size: 0xe0.
// Requires qualifying descriptor-flag distribution and at least one candidate without linked flag8, then copies full party list.
extern "C" bool Combat_CopyPartyCandidatesWhenFlagDistributionAllows(int* self,int unused1,int unused2,int* outputCount,short* output){Four candidates=CombatCopyPartyCandidatesWhenFlagDistributionAllows_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,candidates.values,4,1);if(count<=0)return false;if(!Combat_TestFlaggedCandidatesBelowOneThird(self))return false;*outputCount=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(*self,candidates.values[i]);if(object&&!CombatEffect_TargetHasParalysis(object))++*outputCount;}if(*outputCount<=0)return false;*outputCount=count;memcpy(output,candidates.values,8);return true;}
