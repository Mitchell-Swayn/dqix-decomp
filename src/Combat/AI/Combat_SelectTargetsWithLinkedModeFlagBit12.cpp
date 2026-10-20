#include <globaldefs.h>
ARM
// Original data: arm9/ov024 @ 0x21febe4; symbol: data_ov024_021febe4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Four{short values[4];};extern "C" Four CombatSelectTargetsWithLinkedModeFlagBit12_UnknownRoleInitializedBytes;extern "C" int Combat_TryGetLinkedLivingTargetId(void*,int,short*);extern "C" int Combat_CollectEligiblePartyIds(int,short*,int,int);extern "C" int Combat_TestMonsterDescriptorMode(void*,int,int,int);extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*,int,int,int*,short*);

// Original: arm9/ov024 @ 0x021F22D8; symbol: Combat_FilterPackedModeCandidatesAndApplySelection; size: 0x108.
extern "C" int Combat_SelectTargetsWithLinkedModeFlagBit12(int* self,int selected,int mode,int* outCount,short* output){
Four list=CombatSelectTargetsWithLinkedModeFlagBit12_UnknownRoleInitializedBytes;int count=Combat_TryGetLinkedLivingTargetId(self,selected,list.values);if(count<=0){count=Combat_CollectEligiblePartyIds(*self,list.values,4,1);if(count<=0)return 0;}
 *outCount=0;for(int i=0;i<count;++i)if(Combat_TestMonsterDescriptorMode((void*)*self,list.values[i],0,1))output[(*outCount)++]=list.values[i];if(*outCount<=0)return 0;Combat_SelectWeightedTargetCountFromPackedMode(self,selected,mode,outCount,output);return 1;
}
