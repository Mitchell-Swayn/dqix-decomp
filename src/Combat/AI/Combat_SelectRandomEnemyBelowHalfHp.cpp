#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21fef7c; symbol: data_ov024_021fef7c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" char* _Z16GetCombatantByIDii(void*,int);extern "C" int CombatStatus_HasSleep(void*);extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);extern "C" void* memcpy(void*,const void*,unsigned);struct IDs{short values[8];};extern "C" IDs CombatSelectRandomEnemyBelowHalfHp_UnknownRoleInitializedBytes;extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(void*,short*,int,int);extern "C" float Combat_GetCurrentHealthFraction(void*);extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);
// Original: arm9/ov024 @ 0x021F1C64; symbol: CollectHalfRatioMembersAndSelectRandomFirst; size: 0xE8.
extern "C" int Combat_SelectRandomEnemyBelowHalfHp(void** self,int unused,int unused2,int* countOut,short* out){IDs ids=CombatSelectRandomEnemyBelowHalfHp_UnknownRoleInitializedBytes;int count=Combat_CollectGroupIndicesByDescriptorFlags(*self,ids.values,8,1);if(count<=0)return 0;*countOut=0;for(int i=0;i<count;i++){void* object=_Z16GetCombatantByIDii(*self,ids.values[i]);if(!object)continue;if(Combat_GetCurrentHealthFraction(object)>=0.5f)continue;int slot=(*countOut)++;out[slot]=ids.values[i];}if(*countOut<=0)return 0;Combat_SelectRandomCandidateInPlace(self,countOut,out);return 1;}
