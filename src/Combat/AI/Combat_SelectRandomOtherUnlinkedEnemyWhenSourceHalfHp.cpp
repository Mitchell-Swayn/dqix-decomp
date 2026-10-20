#include "globaldefs.h"
#include "std_library_functions.h"
#define H(p,o) (*(unsigned short*)((unsigned char*)(p)+(o)))
#define S(p,o) (*(short*)((unsigned char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((unsigned char*)(p)+(o)))
#define P(p,o) (*(unsigned char**)((unsigned char*)(p)+(o)))
#include "Combat/Overlay_0/GetCombatantByID.h"
// Original data: arm9/ov024 @ 0x21feccc; symbol: data_ov024_021feccc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern short CombatSelectRandomOtherUnlinkedEnemyWhenSourceHalfHp_UnknownRoleInitializedBytes[];extern "C" GameObject*Combat_FindIndexedMonsterObject(void*,int);extern "C" float Combat_GetCurrentHealthFraction(unsigned char*);extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned),Combat_SelectRandomCandidateInPlace(void**,int*,short*);
// Original: arm9/ov024 @ 0x021F2754; symbol: func_ov024_021f2754; size: 0x118.
extern "C" ARM int Combat_SelectRandomOtherUnlinkedEnemyWhenSourceHalfHp(void**self,int excluded,int unused,int*count,short*out){GameObject*object=((GameObject*(*)(void*))Combat_FindIndexedMonsterObject)(*self);if(!object)return 0;if(Combat_GetCurrentHealthFraction((unsigned char*)object)<0.5f)return 0;struct Seed{short ids[8];};Seed seed=*(const Seed*)CombatSelectRandomOtherUnlinkedEnemyWhenSourceHalfHp_UnknownRoleInitializedBytes;int total=Combat_CollectGroupIndicesByDescriptorFlags((char*)*self,seed.ids,8,1);if(total<=0)return 0;*count=0;for(int i=0;i<total;i++){if(excluded==seed.ids[i])continue;GameObject*candidate=GetCombatantByID((int)*self,seed.ids[i]);if(candidate&&S(P(candidate,0x138),0x2c)<0){int at=(*count)++;out[at]=seed.ids[i];}}if(*count<=0)return 0;Combat_SelectRandomCandidateInPlace(self,count,out);return 1;}