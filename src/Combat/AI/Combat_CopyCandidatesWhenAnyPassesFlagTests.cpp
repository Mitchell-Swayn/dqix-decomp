#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" int CombatEffect_TargetHasDazzle(...);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(...);
extern "C" void memcpy(...);
// Original data: arm9/ov024 @ 0x21fef2c; symbol: data_ov024_021fef2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Eight;extern "C" Eight CombatCopyCandidatesWhenAnyPassesFlagTests_UnknownRoleInitializedBytes;
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov024 @ 0x021F125C; symbol: Combat_CopyCandidatesWhenAnyPassesFlagTests; size: 0xd4.
// Copies the eight-halfword candidate array and count when any selected candidate passes flags40 and200.
extern "C" bool Combat_CopyCandidatesWhenAnyPassesFlagTests(int* self,int unused1,int unused2,int* outputCount,short* output){Eight candidates=CombatCopyCandidatesWhenAnyPassesFlagTests_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,candidates.values,4,1);if(count<=0)return false;int found=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(*self,candidates.values[i]);if(object&&!CombatEffect_TargetHasDazzle(object)&&!Combatant_TestPrimaryStatusFlagBit9(object)){found=1;break;}}if(!found)return false;*outputCount=count;memcpy(output,candidates.values,16);return true;}
