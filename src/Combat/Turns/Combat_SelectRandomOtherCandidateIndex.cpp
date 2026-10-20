#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(...);
extern "C" int _Z13NextRandomMaxP6Randomi(...);
extern "C" Eight Combat_SelectRandomOtherCandidateIndex_CombatantSelectionInitialIds_Copy2;
extern "C" Eight Combat_SelectRandomOtherCandidateIndex_CombatantSelectionInitialIds;
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x02153D78; symbol: Combat_SelectRandomOtherCandidateIndex; size: 0xc8.
// Combat SelectRandomOtherCandidateIndex from listed field operations and calls.
extern "C" void Combat_SelectRandomOtherCandidateIndex(void* self,int excluded,short* output){Eight candidates=Combat_SelectRandomOtherCandidateIndex_CombatantSelectionInitialIds_Copy2;short* list=candidates.values;int count=Combat_CollectGroupIndicesByDescriptorFlags(self,list,8,1);Eight alternatives=Combat_SelectRandomOtherCandidateIndex_CombatantSelectionInitialIds;int used=0;short* available=alternatives.values;for(int i=0;i<count;++i)if(excluded!=list[i])available[used++]=list[i];if(used<=0)*output=excluded;else *output=available[_Z13NextRandomMaxP6Randomi(self,used)];}
