#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned CombatStatus_HasSleep(...);
extern "C" unsigned _Z16GetCombatantByIDii(...);
extern "C" unsigned Combat_CollectEligiblePartyIds(...);
// Original data: arm9/ov024 @ 0x21feb54; symbol: data_ov024_021feb54.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned char CombatCopyPartyIdsWhenAnyLacksDamageRecoverableAilment_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021f0748; symbol: FindCombatantsWithoutElementMask10.
extern "C" int Combat_CopyPartyIdsWhenAnyLacksDamageRecoverableAilment(char* p,int unused1,int unused2,int* count,short* output){struct Four{short v[4];};Four local=*(const Four*)CombatCopyPartyIdsWhenAnyLacksDamageRecoverableAilment_UnknownRoleInitializedBytes;int length=Combat_CollectEligiblePartyIds(U(p,0),local.v,4,1);if(length<=0)return 0;int found=0;for(int i=0;i<length;i++){char* object=(char*)_Z16GetCombatantByIDii(U(p,0),local.v[i]);if(object&&!CombatStatus_HasSleep((void*)U(object,0x138))){found=1;break;}}if(!found)return 0;*count=length;memcpy(output,local.v,8);return 1;}
