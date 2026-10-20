#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21fec04; symbol: data_ov024_021fec04.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char* _Z16GetCombatantByIDii(int,int);extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);extern "C" bool GameObject_IsDead(void*);struct Table8{short values[8];};struct Table4{short values[4];};struct Packed{char pad[88];signed a:3;signed b:3;signed c:3;signed rest:23;};extern "C" const Table4 CombatFilterAndProcessTargetsWithoutLinkedDescriptorFlag8_UnknownRoleInitializedBytes;extern "C" int CombatEffect_TargetHasParalysis(unsigned char*);extern "C" int Combat_TryGetLinkedLivingTargetId(void*,int,short*);extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*,int,int,int*,short*);
// Original: arm9/ov024 @ 0x021F1E58; symbol: Combat_FilterAndProcessTargetsWithoutLinkedDescriptorFlag8; size: 0x10C.
extern "C" int Combat_FilterAndProcessTargetsWithoutLinkedDescriptorFlag8(char* self,int index,int mode,int* count,short* output){Table4 candidates=CombatFilterAndProcessTargetsWithoutLinkedDescriptorFlag8_UnknownRoleInitializedBytes;int length=Combat_TryGetLinkedLivingTargetId(self,index,candidates.values);if(length<=0){length=Combat_CollectEligiblePartyIds(P(self,0),candidates.values,4,1);if(length<=0)return 0;}*count=0;for(int i=0;i<length;i++){char* actor=_Z16GetCombatantByIDii(I(self,0),candidates.values[i]);if(actor&&!CombatEffect_TargetHasParalysis((unsigned char*)actor)){int slot=*count;*count=slot+1;output[slot]=candidates.values[i];}}if(*count<=0)return 0;Combat_SelectWeightedTargetCountFromPackedMode(self,index,mode,count,output);return 1;}
