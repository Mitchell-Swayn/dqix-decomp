#include <globaldefs.h>
ARM
extern "C" float Combat_GetCurrentHealthFraction(...);
extern "C" int Combat_SelectRandomCandidateInPlace(...);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov024 @ 0x21fec9c; symbol: data_ov024_021fec9c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char CombatSelectRandomUnflaggedEnemyBelowHalfHp_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021EE6A8; symbol: SelectRandomUnflaggedCombatantBelowHalfRatio.
extern "C" int Combat_SelectRandomUnflaggedEnemyBelowHalfHp(char*self,int unused,int unused2,int*count,short*output){
struct Ids{short values[8];};Ids ids=*(Ids*)CombatSelectRandomUnflaggedEnemyBelowHalfHp_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags(W(self,0),ids.values,8,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;i++){char*object=C(_Z16GetCombatantByIDii(W(self,0),ids.values[i]));if(!object)continue;if(Combatant_TestPrimaryStatusFlagBit9(object))continue;if(Combat_GetCurrentHealthFraction(object)>=0.5f)continue;output[*count]=ids.values[i];(*count)++;}if(*count<=0)return 0;Combat_SelectRandomCandidateInPlace(self,count,output);return 1;
}
