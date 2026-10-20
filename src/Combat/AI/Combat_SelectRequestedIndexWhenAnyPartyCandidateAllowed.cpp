#include <globaldefs.h>
ARM
extern "C" char* Combat_FindIndexedMonsterObject(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
extern "C" int Combat_TestPartyFlagsAndUnrestrictedDescriptor(...);
// Original data: arm9/ov024 @ 0x21fed8c; symbol: data_ov024_021fed8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Eight;extern "C" Eight CombatSelectRequestedIndexWhenAnyPartyCandidateAllowed_UnknownRoleInitializedBytes;
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};struct Vec {int x,y,z;};
// Original: arm9/ov024 @ 0x021F3168; symbol: Combat_SelectRequestedIndexWhenAnyPartyCandidateAllowed; size: 0xe0.
// Validates requested object restriction field and returns requested index when any party candidate passes descriptor tests.
extern "C" bool Combat_SelectRequestedIndexWhenAnyPartyCandidateAllowed(int* self,int index,int unused,int* outputCount,short* output){char* object=Combat_FindIndexedMonsterObject(*self,index);if(!object)return false;struct Restriction {unsigned low:18;signed level:3;unsigned rest:11;};if(((Restriction*)(P(object,0x138)+0x58))->level>=2)return false;Eight candidates=CombatSelectRequestedIndexWhenAnyPartyCandidateAllowed_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,candidates.values,4,1);if(count<=0)return false;int found=0;for(int i=0;i<count;++i)if(Combat_TestPartyFlagsAndUnrestrictedDescriptor(self,candidates.values[i])){found=1;break;}if(!found)return false;*outputCount=1;*output=index;return true;}
