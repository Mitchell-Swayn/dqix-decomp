#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21fec34; symbol: data_ov024_021fec34.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char* _Z16GetCombatantByIDii(void*,int);extern "C" void* memcpy(void*,const void*,unsigned);extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);extern "C" int CombatStatus_HasSleep(void*);struct Flag{char pad[0x58];int before:18;int value:3;int rest:11;};struct IDs{short values[4];};extern "C" IDs CombatCopyPartyIdsWhenAnyUnflaggedModifierCanDecrease_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F1768; symbol: CopyCollectedMembersWhenSignedFlagExceedsMinusTwo; size: 0xDC.
extern "C" int Combat_CopyPartyIdsWhenAnyUnflaggedModifierCanDecrease(void** self,int unused,int unused2,int* countOut,void* out){IDs ids=CombatCopyPartyIdsWhenAnyUnflaggedModifierCanDecrease_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,ids.values,4,1);if(count<=0)return 0;int found=0;for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*self,ids.values[i]);if(!object||Combatant_TestPrimaryStatusFlagBit9(object))continue;if(-2<((Flag*)P(object,0x138))->value){found=1;break;}}if(!found)return 0;*countOut=count;memcpy(out,&ids,8);return 1;}
