#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct PartyIds { short values[4]; };
// Original data: arm9/ov024 @ 0x21feafc; symbol: data_ov024_021feafc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" const PartyIds CombatCollectFourEligiblePartyIds_UnknownRoleInitializedBytes;
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
// Original: arm9/ov024 @ 0x021EE3E8; symbol: func_ov024_021ee3e8; size: 0x6C.
// Copies the initial four-short template, collects eligible IDs, and publishes successful output.
extern "C" int Combat_CollectFourEligiblePartyIds(void** context,int unused1,int unused2,int* count,short* output)
{
 PartyIds ids=CombatCollectFourEligiblePartyIds_UnknownRoleInitializedBytes;
 int found=Combat_CollectEligiblePartyIds(*context,ids.values,4,1);
 if(found<=0)return 0;
 *count=found;
 memcpy(output,&ids,8);
 return 1;
}
