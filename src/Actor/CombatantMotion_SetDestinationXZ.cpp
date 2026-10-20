#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02049BD4; symbol: func_02049bd4; size: 0x34.
extern "C" void CombatantMotion_SetDestinationXZ(unsigned char* p,unsigned* value){unsigned* q=*(unsigned**)(p+316);if(!q)return;q[4]=value[0];(*(unsigned**)(p+316))[6]=value[2];(*(unsigned**)(p+316))[8]&=~1U;}
