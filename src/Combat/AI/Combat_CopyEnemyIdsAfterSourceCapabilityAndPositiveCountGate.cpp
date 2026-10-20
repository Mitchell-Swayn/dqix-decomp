#include <globaldefs.h>
ARM
extern "C" int Combat_FindIndexedMonsterObject(...);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" int Combatant_TestTargetCapabilityBit2(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov024 @ 0x21fef6c; symbol: data_ov024_021fef6c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char CombatCopyEnemyIdsAfterSourceCapabilityAndPositiveCountGate_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021F166C; symbol: CopyCombatantIdsWhenStateFieldAllowsSelection.
extern "C" int Combat_CopyEnemyIdsAfterSourceCapabilityAndPositiveCountGate(char*self,int index,int unused,int*count,short*output){
char*object=C(Combat_FindIndexedMonsterObject(W(self,0),index));if(!object)return 0;if(!Combatant_TestTargetCapabilityBit2(object))return 0;struct Ids{short values[8];};Ids ids=*(Ids*)CombatCopyEnemyIdsAfterSourceCapabilityAndPositiveCountGate_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags(W(self,0),ids.values,8,1);if(total<=0)return 0;for(int i=0;i<total;i++){char*entry=C(_Z16GetCombatantByIDii(W(self,0),ids.values[i]));if(!entry)continue;if(Combatant_TestPrimaryStatusFlagBit9(entry))continue;struct Field{unsigned pad:21;signed state:3;unsigned high:8;};if(((Field*)(P(entry,0x138)+88))->state<2)break;}if(*count<=0)return 0;*count=total;memcpy(output,ids.values,16);return 1;
}
