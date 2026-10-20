#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct SignedThree{signed value:3;unsigned other:29;};
extern "C" unsigned _Z16GetCombatantByIDii(...);
extern "C" unsigned Combat_CollectEligiblePartyIds(...);
// Original data: arm9/ov024 @ 0x21feb74; symbol: data_ov024_021feb74.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned char BattleAICopyPartyWhenAttackAndCounterAt4FAllowLowering_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021f3440; symbol: FindCombatantsWithPositiveField4FAndModeAboveMinusTwo.
extern "C" int BattleAI_CopyPartyWhenAttackAndCounterAt4FAllowLowering(char* p,int unused1,int unused2,int* count,short* output){struct Four{short ids[4];};Four list=*(Four*)BattleAICopyPartyWhenAttackAndCounterAt4FAllowLowering_UnknownRoleInitializedBytes;int length=Combat_CollectEligiblePartyIds(U(p,0),list.ids,4,1);if(length<=0)return 0;int found=0;for(int i=0;i<length;i++){char* object=(char*)_Z16GetCombatantByIDii(U(p,0),list.ids[i]);if(object){char* state=(char*)U(object,0x138);if(H(state,8)&&((SignedThree*)(state+0x58))->value>-2&&(short)B(state,0x4f)>0){found=1;break;}}}if(!found)return 0;*count=length;memcpy(output,list.ids,8);return 1;}
