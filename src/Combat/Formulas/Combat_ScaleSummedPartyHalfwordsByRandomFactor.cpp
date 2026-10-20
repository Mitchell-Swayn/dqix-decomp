#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv(...);
extern "C" char* GameState_GetObjectWithFlag100(...);
extern "C" int Combat_CollectEligiblePartyIds(...);
// Original data: arm9/ov024 @ 0x21fe6c8; symbol: data_ov024_021fe6c8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Four;extern "C" Four CombatScaleSummedPartyHalfwordsByRandomFactor_UnknownRoleInitializedBytes;
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(int,float,float);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov024 @ 0x021DA47C; symbol: Combat_ScaleSummedPartyHalfwordsByRandomFactor; size: 0xd4.
// Sums party descriptor halfwords and multiplies by random0.95..1.5 for valid index0..3.
extern "C" int Combat_ScaleSummedPartyHalfwordsByRandomFactor(int* self,unsigned index,int unused1,int unused2,int unused3,int fallback){int valid;if(index<=3)valid=1;else valid=0;if(!valid)return fallback;char* game=_ZN9GameState11GetInstanceEv();int sum=0;Four candidates=CombatScaleSummedPartyHalfwordsByRandomFactor_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(*self,candidates.values,4,1);for(int i=0;i<count;++i){char* object=GameState_GetObjectWithFlag100(game,candidates.values[i]);if(object)sum+=H(P(object,0x138),8);}float factor=_Z22NextRandomFloatBetweenP6Randomff(*self,0.95f,1.5f);return (int)((float)sum*factor);}
