#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02087838; symbol: func_02087838; size: 0x28.
void CombatStatus_ClearAttackStage(char *p){*(unsigned int *)(p+0x14)&=~0x400;*(unsigned int *)(p+0x58)&=~0x7;*(unsigned char *)(p+0x6e)=0;*(unsigned char *)(p+0x91)=0;}
}
