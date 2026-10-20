#include <globaldefs.h>
ARM
// Original data: arm9/ov024 @ 0x21fe6d8; symbol: data_ov024_021fe6d8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatCountListedCombatantsWithFlagThree_UnknownRoleInitializedBytes[4];
extern "C" int Combat_CollectEligiblePartyIds(int,short*,int,int);
extern "C" char* _Z16GetCombatantByIDii(int,int);
struct Flag {unsigned char low:3;unsigned char selected:1;unsigned char rest:4;};
// Original: arm9/ov024 @ 0x021EB2B4; symbol: Combat_CountListedCombatantsWithFlagThree; size: 0x90.
extern "C" int Combat_CountListedCombatantsWithFlagThree(char* self) {
 struct Four {short ids[4];};int result=0;Four local=*(Four*)CombatCountListedCombatantsWithFlagThree_UnknownRoleInitializedBytes; int count=Combat_CollectEligiblePartyIds(*(int*)(self+16),local.ids,4,1);
 for(int i=0;i<count;i++){char* obj=_Z16GetCombatantByIDii(*(int*)(self+16),local.ids[i]);if(((Flag*)(*(char**)(obj+0x138)+0x3b))->selected)result++;}return result;
}
