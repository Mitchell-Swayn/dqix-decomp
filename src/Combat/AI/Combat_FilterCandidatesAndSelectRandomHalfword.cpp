#include <globaldefs.h>
ARM
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" int Combat_TestCandidateFlagsOrNegativePackedStatus(...);
extern "C" void Combat_SelectRandomCandidateInPlace(...);
// Original data: arm9/ov024 @ 0x21fed5c; symbol: data_ov024_021fed5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Eight;extern "C" Eight CombatFilterCandidatesAndSelectRandomHalfword_UnknownRoleInitializedBytes;
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov024 @ 0x021F2F78; symbol: Combat_FilterCandidatesAndSelectRandomHalfword; size: 0xd4.
// Filters eight candidate halfwords through predicate and randomly selects qualifying first slot.
extern "C" bool Combat_FilterCandidatesAndSelectRandomHalfword(int* self,int unused1,int unused2,int* outputCount,short* output){Eight candidates=CombatFilterCandidatesAndSelectRandomHalfword_UnknownRoleInitializedBytes;int count=Combat_CollectGroupIndicesByDescriptorFlags(*self,candidates.values,8,1);if(count<=0)return false;*outputCount=0;for(int i=0;i<count;++i){if(Combat_TestCandidateFlagsOrNegativePackedStatus(self,candidates.values[i]))output[(*outputCount)++]=candidates.values[i];}if(*outputCount<=0)return false;Combat_SelectRandomCandidateInPlace(self,outputCount,output);return true;}
