#include <globaldefs.h>
ARM
struct Codes {unsigned short value[4];};
// Original data: arm9/ov024 @ 0x21feaa4; symbol: data_ov024_021feaa4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" Codes BattleAICopyPartyAfterFlagDistributionGate_UnknownRoleInitializedBytes;
extern "C" int Combat_CollectEligiblePartyIds(void*,unsigned short*,int,int);
extern "C" int Combat_TestFlaggedCandidatesBelowOneThird(void*);
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/ov024 @ 0x021F639C; symbol: ReadFourCodeSelectionAndCopyOnReady; size: 0x88.
// Queries four halfword codes and copies them when a positive selection and readiness agree.
extern "C" int BattleAI_CopyPartyAfterFlagDistributionGate(void** self,int unused1,int unused2,int* count,void* out) {
Codes codes=BattleAICopyPartyAfterFlagDistributionGate_UnknownRoleInitializedBytes;
int selected=Combat_CollectEligiblePartyIds(*self,codes.value,4,1);
if(selected<=0)return 0;if(!Combat_TestFlaggedCandidatesBelowOneThird(self))return 0;
*count=selected;memcpy(out,&codes,8);return 1;
}
