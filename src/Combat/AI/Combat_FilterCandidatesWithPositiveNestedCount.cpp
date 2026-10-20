#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21feb14; symbol: data_ov024_021feb14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatFilterCandidatesWithPositiveNestedCount_UnknownRoleInitializedBytes[4];
extern "C" int Combat_TryGetLinkedLivingTargetId(void*,int,short*);
extern "C" int Combat_CollectEligiblePartyIds(int,short*,int,unsigned);
extern "C" void* _Z16GetCombatantByIDii(int,int);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*,int,int,int*,short*);
// Original: arm9/ov024 @ 0x021f4768; symbol: Combat_FilterCandidatesWithPositiveNestedCount; size 0x110.
extern "C" int Combat_FilterCandidatesWithPositiveNestedCount(void* self,int descriptor,int mode,int* count,short* output){struct Ids{short value[4];};Ids ids=*(Ids*)CombatFilterCandidatesWithPositiveNestedCount_UnknownRoleInitializedBytes;int n=Combat_TryGetLinkedLivingTargetId(self,descriptor,ids.value);if(n<=0){n=Combat_CollectEligiblePartyIds(W(self,0),ids.value,4,1);if(n<=0)return 0;}*count=0;for(int i=0;i<n;i++){void* p=_Z16GetCombatantByIDii(W(self,0),ids.value[i]);if(p&&H(P(p,0x138),2)>=1)output[(*count)++]=ids.value[i];}if(*count<=0)return 0;Combat_SelectWeightedTargetCountFromPackedMode(self,descriptor,mode,count,output);return 1;}
