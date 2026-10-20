#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(...);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" int CombatEffect_TargetHasParalysis(...);
extern "C" void Combat_SelectRandomCandidateInPlace(...);
// Original data: arm9/ov024 @ 0x21fec8c; symbol: data_ov024_021fec8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Eight;extern "C" Eight CombatSelectRandomCandidateWithLinkedFlag8_UnknownRoleInitializedBytes;
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};struct Vec {int x,y,z;};
// Original: arm9/ov024 @ 0x021F4974; symbol: Combat_SelectRandomCandidateWithLinkedFlag8; size: 0xe0.
// Filters candidate halfwords by object flags and selects a random qualifying entry into first slot.
extern "C" bool Combat_SelectRandomCandidateWithLinkedFlag8(int* self,int unused1,int unused2,int* outputCount,short* output){Eight candidates=CombatSelectRandomCandidateWithLinkedFlag8_UnknownRoleInitializedBytes;int count=Combat_CollectGroupIndicesByDescriptorFlags(*self,candidates.values,8,1);if(count<=0)return false;*outputCount=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(*self,candidates.values[i]);if(object&&CombatEffect_TargetHasParalysis(object))output[(*outputCount)++]=candidates.values[i];}if(*outputCount<=0)return false;Combat_SelectRandomCandidateInPlace(self,outputCount,output);return true;}
