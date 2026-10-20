#include <globaldefs.h>
ARM
// Original data: arm9/ov024 @ 0x21fef8c; symbol: data_ov024_021fef8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff00000000000000000000000000000a000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Ids{short values[8];};extern "C" {extern Ids BattleAISelectActorWhenNoEnemyOfSpecies180Exists_UnknownRoleInitializedBytes;int Combat_CollectGroupIndicesByDescriptorFlags(void*,short*,int,int);char* Combat_FindIndexedMonsterObject(void*,int);}
// Original: arm9/ov024 @ 0x021F65FC; symbol: EmitFallbackIdWhenNoType180TargetExists; size: 0xc4.
// Counts indexed type180 targets and emits one fallback ID only when none exist.
extern "C" int BattleAI_SelectActorWhenNoEnemyOfSpecies180Exists(void** self,unsigned short value,int unused,int* count,unsigned short* output){Ids local=BattleAISelectActorWhenNoEnemyOfSpecies180Exists_UnknownRoleInitializedBytes;int n=Combat_CollectGroupIndicesByDescriptorFlags(*self,local.values,8,1);if(n<=0)return 0;*count=0;for(int i=0;i<n;++i){char* object=Combat_FindIndexedMonsterObject(*self,local.values[i]);if(object&&*(short*)(object+2)==180)++*count;}if(*count>0)return 0;*count=1;*output=value;return 1;}
