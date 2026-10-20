#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov024 @ 0x21fec44; symbol: data_ov024_021fec44.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Four{short values[4];};extern "C" {int Combat_CollectEligiblePartyIds(int,short*,int,int);bool Combat_TestFlaggedCandidatesBelowOneThird(int*);unsigned char* _Z16GetCombatantByIDii(int,int);bool CombatStatus_HasSleep(void*);void* memcpy(void*,const void*,unsigned);extern Four BattleAICopyPartyWhenTwoThirdsAreSusceptibleToSleep_UnknownRoleInitializedBytes;}
#pragma always_inline on
inline int Quantity(unsigned char* descriptor){return descriptor[71];}
// Original: arm9/ov024 @0x021f4294; symbol:Combat_CopyAllCandidatesWhenTwoThirdsHaveElementQuantity; size:0x11c.
// Copies original four-id candidate set when at least two thirds pass descriptor flag/quantity tests and flagged group threshold passes.
extern "C" int BattleAI_CopyPartyWhenTwoThirdsAreSusceptibleToSleep(int* self,int unused1,int unused2,int* count,short* output){Four candidates=BattleAICopyPartyWhenTwoThirdsAreSusceptibleToSleep_UnknownRoleInitializedBytes;int total=Combat_CollectEligiblePartyIds(*self,candidates.values,4,1);if(total<=0)return 0;if(!Combat_TestFlaggedCandidatesBelowOneThird(self))return 0;*count=0;for(int i=0;i<total;++i){unsigned char* object=_Z16GetCombatantByIDii(*self,candidates.values[i]);if(!object)continue;if(CombatStatus_HasSleep(P(object,0x138))||Quantity(P(object,0x138))<=0)continue;int next=*count;*count=next+1;output[next]=candidates.values[i];}if(*count<=0)return 0;if(3**count<2*total)return 0;*count=total;memcpy(output,candidates.values,8);return 1;}
