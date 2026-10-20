#include <globaldefs.h>
ARM
extern "C" float Combat_GetCurrentHealthFraction(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov024 @ 0x21fec6c; symbol: data_ov024_021fec6c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char CombatCopyEnemyIdsWhenTwoThirdsBelowHalfHp_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021F20B8; symbol: CopyAllCombatantIdsWhenTwoThirdsBelowHalfRatio.
extern "C" int Combat_CopyEnemyIdsWhenTwoThirdsBelowHalfHp(char*self,int unused,int unused2,int*count,short*output){
struct Ids{short values[8];};Ids ids=*(Ids*)CombatCopyEnemyIdsWhenTwoThirdsBelowHalfHp_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags(W(self,0),ids.values,8,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;i++){char*object=C(_Z16GetCombatantByIDii(W(self,0),ids.values[i]));if(!object)continue;if(Combat_GetCurrentHealthFraction(object)>=0.5f)continue;output[(*count)++]=ids.values[i];}if(*count<=0)return 0;if(*count*3<total*2)return 0;*count=total;memcpy(output,ids.values,16);return 1;
}
