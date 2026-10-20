#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21feddc; symbol: data_ov024_021feddc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char* _Z16GetCombatantByIDii(int,int);extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);extern "C" bool GameObject_IsDead(void*);struct Table8{short values[8];};struct Table4{short values[4];};struct Packed{char pad[88];signed a:3;signed b:3;signed c:3;signed rest:23;};extern "C" const Table8 CombatSelectRandomUnflaggedEnemyWithAttackRaiseAvailable_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F0208; symbol: Combat_CollectAndSelectStatCAvailableTargets; size: 0x10C.
extern "C" int Combat_SelectRandomUnflaggedEnemyWithAttackRaiseAvailable(char* self,int unused,int unused2,int* count,short* output){Table8 candidates=CombatSelectRandomUnflaggedEnemyWithAttackRaiseAvailable_UnknownRoleInitializedBytes;int length=Combat_CollectGroupIndicesByDescriptorFlags(P(self,0),candidates.values,8,1);if(length<=0)return 0;*count=0;for(int i=0;i<length;i++){char* actor=_Z16GetCombatantByIDii(I(self,0),candidates.values[i]);if(actor&&U(P(actor,312),8)<65535&&((Packed*)P(actor,312))->a<2&&!Combatant_TestPrimaryStatusFlagBit9(actor)){int index=*count;*count=index+1;output[index]=candidates.values[i];}}if(*count<=0)return 0;Combat_SelectRandomCandidateInPlace((void**)self,count,output);return 1;}
