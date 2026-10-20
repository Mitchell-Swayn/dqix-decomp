#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov024 @ 0x21febc4; symbol: data_ov024_021febc4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct IDs{short values[4];};extern "C" {extern IDs CombatFilterPreferredTargetsAndDispatchSelection_UnknownRoleInitializedBytes;int Combat_TryGetLinkedLivingTargetId(void*,int,short*);int Combat_CollectEligiblePartyIds(void*,short*,int,int);int Combat_TestPreferredTargetExclusionFlags(void*,int);void Combat_SelectWeightedTargetCountFromPackedMode(void*,int,int,int*,short*);}
// Original: arm9/ov024 @ 0x021F1F64; symbol: Combat_FilterPreferredTargetsAndDispatchSelection; size: 0x100.
// Filters preferred or fallback target IDs before dispatching the requested selection mode.
extern "C" int Combat_FilterPreferredTargetsAndDispatchSelection(unsigned char* self,int kind,int argument,int* count,short* output){IDs ids=CombatFilterPreferredTargetsAndDispatchSelection_UnknownRoleInitializedBytes;int total=Combat_TryGetLinkedLivingTargetId(self,kind,ids.values);if(total<=0){total=Combat_CollectEligiblePartyIds(P(self,0),ids.values,4,1);if(total<=0)return 0;}*count=0;for(int i=0;i<total;++i){if(Combat_TestPreferredTargetExclusionFlags(self,ids.values[i])){int next=*count;*count=next+1;output[next]=ids.values[i];}}if(*count<=0)return 0;Combat_SelectWeightedTargetCountFromPackedMode(self,kind,argument,count,output);return 1;}
