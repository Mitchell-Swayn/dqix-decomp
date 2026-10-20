#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov024 @ 0x21fec5c; symbol: data_ov024_021fec5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatSelectWeightedTargetCountFromPackedMode_UnknownRoleInitializedBytes[8];extern "C" int _Z17NextRandomBetweenP6Randomii(void*,int,int),SelectWeightedEligibleCombatantIndex(void*,unsigned,int,short*);extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/ov024 @ 0x021ed8c0; symbol: Combat_SelectWeightedTargetCountFromPackedMode; size 0x11c.
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void* self,unsigned source,void* descriptor,int* count,short* output){struct Mode{unsigned reserved:14;unsigned value:5;};unsigned mode=((Mode*)((char*)descriptor+28))->value;void* random=P(self,0);int desired=1;switch(mode){case 3:desired=_Z17NextRandomBetweenP6Randomii(random,3,4);break;case 4:desired=2;break;case 5:desired=4;break;case 7:desired=7;break;case 8:desired=3;break;case 9:case 10:desired=1;break;}struct Ids{short values[8];};int found=0;Ids chosen=*(Ids*)CombatSelectWeightedTargetCountFromPackedMode_UnknownRoleInitializedBytes;for(int i=0;i<desired;i++){int id=SelectWeightedEligibleCombatantIndex(P(self,0),source,*count,output);if(id<0)break;chosen.values[found]=id;found=(short)(found+1);}*count=found;memcpy(output,chosen.values,16);}
