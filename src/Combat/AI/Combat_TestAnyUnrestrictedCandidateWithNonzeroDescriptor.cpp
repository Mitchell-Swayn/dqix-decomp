#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(...);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" int CombatEffect_TargetHasFizzle(...);
// Original data: arm9/ov024 @ 0x21febdc; symbol: data_ov024_021febdc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Four;extern "C" Four CombatTestAnyUnrestrictedCandidateWithNonzeroDescriptor_UnknownRoleInitializedBytes;
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov024 @ 0x021F094C; symbol: Combat_TestAnyUnrestrictedCandidateWithNonzeroDescriptor; size: 0xd4.
// Requires valid unmasked target and any candidate with nonzero descriptor halfword and no descriptor flag100.
extern "C" int Combat_TestAnyUnrestrictedCandidateWithNonzeroDescriptor(int* self,int index){char* target=_Z16GetCombatantByIDii(*self,index);if(!target)return false;if(Combatant_TestPrimaryStatusFlagBit9(target))return false;Four candidates=CombatTestAnyUnrestrictedCandidateWithNonzeroDescriptor_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,candidates.values,4,1);if(count<=0)return false;int found=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(*self,candidates.values[i]);if(object&&!CombatEffect_TargetHasFizzle(object)&&H(P(object,0x138),2))found=1;}return found;}
