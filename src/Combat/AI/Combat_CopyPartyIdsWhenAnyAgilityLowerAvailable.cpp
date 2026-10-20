#include <globaldefs.h>
ARM
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov024 @ 0x21feacc; symbol: data_ov024_021feacc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char CombatCopyPartyIdsWhenAnyAgilityLowerAvailable_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021EFF3C; symbol: func_021eff3c.
extern "C" int Combat_CopyPartyIdsWhenAnyAgilityLowerAvailable(char* self,int unused,int unused2,int* count,short* output){
struct Ids{short values[4];};Ids ids=*(Ids*)CombatCopyPartyIdsWhenAnyAgilityLowerAvailable_UnknownRoleInitializedBytes;int total=Combat_CollectEligiblePartyIds(W(self,0),ids.values,4,1);if(total<=0)return 0;int found=0;for(int i=0;i<total;i++){char* object=C(_Z16GetCombatantByIDii(W(self,0),ids.values[i]));if(object){char* nested=P(object,0x138);struct Stats{signed a:3;signed b:3;signed c:3;unsigned pad:3;signed d:3;unsigned pad2:6;signed e:3;unsigned rest:8;};Stats* fields=(Stats*)(nested+88);if(H(nested,12)&&fields->c>-2){found=1;break;}}}if(!found)return 0;*count=total;memcpy(output,ids.values,8);return 1;
}
