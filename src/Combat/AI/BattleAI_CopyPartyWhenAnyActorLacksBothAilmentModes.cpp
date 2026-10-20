#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21fea8c; symbol: data_ov024_021fea8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char* _Z16GetCombatantByIDii(int,int);extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);extern "C" bool GameObject_IsDead(void*);struct Table8{short values[8];};struct Table4{short values[4];};struct Packed{char pad[88];signed a:3;signed b:3;signed c:3;signed rest:23;};extern "C" const Table4 BattleAICopyPartyWhenAnyActorLacksBothAilmentModes_UnknownRoleInitializedBytes;extern "C" bool Combat_TestFlaggedCandidatesBelowOneThird(int*);extern "C" int CombatStatus_HasAilmentModeOne(void*);extern "C" int CombatStatus_HasAilmentModeTwo(void*);extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/ov024 @ 0x021F4A54; symbol: Combat_CopyGroupTargetsWhenEligibleCombatantsExist; size: 0x10C.
extern "C" int BattleAI_CopyPartyWhenAnyActorLacksBothAilmentModes(char* self,int unused,int unused2,int* count,short* output){Table4 candidates=BattleAICopyPartyWhenAnyActorLacksBothAilmentModes_UnknownRoleInitializedBytes;int length=Combat_CollectEligiblePartyIds(P(self,0),candidates.values,4,1);if(length<=0)return 0;if(!Combat_TestFlaggedCandidatesBelowOneThird((int*)self))return 0;*count=0;for(int i=0;i<length;i++){char* actor=_Z16GetCombatantByIDii(I(self,0),candidates.values[i]);if(actor&&!CombatStatus_HasAilmentModeOne(P(actor,312))&&!CombatStatus_HasAilmentModeTwo(P(actor,312))){int slot=*count;*count=slot+1;output[slot]=candidates.values[i];}}if(*count<=0)return 0;*count=length;memcpy(output,&candidates,8);return 1;}
