#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02087DF0; symbol: func_02087df0; size: 0x28.
void CombatStatus_ClearSpellResistanceStage(char *p){*(unsigned int *)(p+0x14)&=~0x10000;*(unsigned int *)(p+0x58)&=~0x1c0000;*(unsigned char *)(p+0x74)=0;*(unsigned char *)(p+0x97)=0;}
}
