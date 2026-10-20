#include <globaldefs.h>
ARM
#include <std_library_functions.h>
// Original data: arm9/ov024 @ 0x21feabc; symbol: data_ov024_021feabc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Four{short values[4];};struct Mode{unsigned low:6;signed value:3;unsigned high:23;};extern "C" Four BattleAICopyPartyWhenTwoThirdsAgilityCanBeLowered_UnknownRoleInitializedBytes;extern "C" int Combat_CollectEligiblePartyIds(int,short*,int,int);extern "C" char* _Z16GetCombatantByIDii(int,int);

// Original: arm9/ov024 @ 0x021F50CC; symbol: Combat_EmitFullListWhenTwoThirdsHaveEligibleMode; size: 0x108.
extern "C" int BattleAI_CopyPartyWhenTwoThirdsAgilityCanBeLowered(int* self,int unused1,int unused2,int* countOut,short* output){
Four list=BattleAICopyPartyWhenTwoThirdsAgilityCanBeLowered_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,list.values,4,1);if(count<=0)return 0;*countOut=0;
 for(int i=0;i<count;++i){char *object=_Z16GetCombatantByIDii(*self,list.values[i]);if(object){char *descriptor=*(char**)(object+0x138);if(*(unsigned short*)(descriptor+12)&&((Mode*)(descriptor+0x58))->value>-2)output[(*countOut)++]=list.values[i];}}
 if(*countOut<=0)return 0;if(*countOut*3<count*2)return 0;*countOut=count;memcpy(output,list.values,8);return 1;
}
