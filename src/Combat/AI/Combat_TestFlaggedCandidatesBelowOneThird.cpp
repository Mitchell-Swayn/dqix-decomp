#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" int Combatant_TestPrimaryStatusFlagBit26(...);
// Original data: arm9/ov024 @ 0x21fea44; symbol: data_ov024_021fea44.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Four;extern "C" Four CombatTestFlaggedCandidatesBelowOneThird_UnknownRoleInitializedBytes;
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov024 @ 0x021EDE2C; symbol: Combat_TestFlaggedCandidatesBelowOneThird; size: 0xd4.
// Counts candidates with linked descriptor flag04000000 and tests whether fewer than one third qualify.
extern "C" bool Combat_TestFlaggedCandidatesBelowOneThird(int* self){Four candidates=CombatTestFlaggedCandidatesBelowOneThird_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,candidates.values,4,1);if(count<=0)return false;short flagged[4]={0};unsigned short used=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(*self,candidates.values[i]);if(object&&Combatant_TestPrimaryStatusFlagBit26(object))flagged[used++]=candidates.values[i];}return 3*used<count;}
