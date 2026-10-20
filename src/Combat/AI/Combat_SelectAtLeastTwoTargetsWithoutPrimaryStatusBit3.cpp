#include <globaldefs.h>
ARM
extern "C" int CombatEffect_TargetHasParalysis(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" int Combat_SelectWeightedTargetCountFromPackedMode(...);
extern "C" int Combat_TryGetLinkedLivingTargetId(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov024 @ 0x21febfc; symbol: data_ov024_021febfc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char CombatSelectAtLeastTwoTargetsWithoutPrimaryStatusBit3_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021EE454; symbol: FilterAtLeastTwoCombatantsWithoutDescriptorFlagEight.
extern "C" int Combat_SelectAtLeastTwoTargetsWithoutPrimaryStatusBit3(char*self,int index,int mode,int*count,short*output){
struct Slots{short data[4];};Slots slots=*(Slots*)CombatSelectAtLeastTwoTargetsWithoutPrimaryStatusBit3_UnknownRoleInitializedBytes;int total=Combat_TryGetLinkedLivingTargetId(self,index,slots.data);if(total<=0){total=Combat_CollectEligiblePartyIds(P(self,0),slots.data,4,1);if(total<=0)return 0;}*count=0;for(int i=0;i<total;i++){int actor=_Z16GetCombatantByIDii(P(self,0),slots.data[i]);if(actor&&!CombatEffect_TargetHasParalysis(actor)){output[*count]=slots.data[i];(*count)++;}}if(*count<2){*count=0;return 0;}Combat_SelectWeightedTargetCountFromPackedMode(self,index,mode,count,output);return output[0]>=0;
}
