#include <globaldefs.h>
ARM
extern "C" int Combat_HasSuperHighTension(...);
extern "C" int _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov024 @ 0x21fed9c; symbol: data_ov024_021fed9c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char BattleAICopyEnemiesWhenAnyLacksRecordBit24_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov024 @ 0x021F5CE4; symbol: CopyCombatantIdsWhenAnyHasClearRecordFlag.
extern "C" int BattleAI_CopyEnemiesWhenAnyLacksRecordBit24(char* self,int unused,int unused2,int* count,short* output){
struct IdList{short values[8];};IdList list=*(IdList*)BattleAICopyEnemiesWhenAnyLacksRecordBit24_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags(P(self,0),list.values,8,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;i++){void* object=(void*)_Z16GetCombatantByIDii(W(self,0),list.values[i]);if(object&&!Combat_HasSuperHighTension(object))(*count)++;}if(*count<=0)return 0;*count=total;memcpy(output,list.values,16);return 1;
}
