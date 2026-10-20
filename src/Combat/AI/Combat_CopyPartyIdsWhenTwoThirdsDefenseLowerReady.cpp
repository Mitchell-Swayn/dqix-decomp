#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21feab4; symbol: data_ov024_021feab4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct IDs{short values[4];};extern "C" IDs CombatCopyPartyIdsWhenTwoThirdsDefenseLowerReady_UnknownRoleInitializedBytes;extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);extern "C" char* _Z16GetCombatantByIDii(void*,int);extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/ov024 @ 0x021EF6C4; symbol: CollectMembersWhenTwoThirdsPassSecondStatFlag; size: 0xF4.
extern "C" int Combat_CopyPartyIdsWhenTwoThirdsDefenseLowerReady(void** self,int unused,int unused2,int* countOut,void* output){IDs ids=CombatCopyPartyIdsWhenTwoThirdsDefenseLowerReady_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,ids.values,4,1);if(count<=0)return 0;int valid=0;int minimum=-2;for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*self,ids.values[i]);if(!object)continue;char* record=P(object,0x138);if(!U(record,10))continue;if(minimum>=((int)(W(record,88)<<26)>>29))continue;if(Combatant_TestPrimaryStatusFlagBit9(object))continue;if((int)B(P(object,0x138),80)>0)valid++;}if(valid*3<count*2)return 0;*countOut=count;memcpy(output,&ids,8);return 1;}
