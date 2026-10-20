#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct SignedThree{signed value:3;unsigned other:29;};
extern "C" unsigned CombatStatus_HasSleep(...);
extern "C" unsigned Combat_SelectRandomCandidateInPlace(...);
extern "C" unsigned _Z16GetCombatantByIDii(...);
extern "C" unsigned Combat_CollectEligiblePartyIds(...);
// Original data: arm9/ov024 @ 0x21feb8c; symbol: data_ov024_021feb8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned char BattleAISelectRandomPartyMemberWithoutRecoverableAilment_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021f606c; symbol: CollectCombatantsWithoutMask10AndSelectRandomFirst.
extern "C" int BattleAI_SelectRandomPartyMemberWithoutRecoverableAilment(char* p,int unused1,int unused2,int* count,short* output){struct Four{short ids[4];};Four list=*(Four*)BattleAISelectRandomPartyMemberWithoutRecoverableAilment_UnknownRoleInitializedBytes;int length=Combat_CollectEligiblePartyIds(U(p,0),list.ids,4,1);if(length<=0)return 0;*count=0;for(int i=0;i<length;i++){char* object=(char*)_Z16GetCombatantByIDii(U(p,0),list.ids[i]);if(object&&!CombatStatus_HasSleep(U(object,0x138))){int index=(*count)++;output[index]=list.ids[i];}}if(*count<=0)return 0;Combat_SelectRandomCandidateInPlace(p,count,output);return 1;}
