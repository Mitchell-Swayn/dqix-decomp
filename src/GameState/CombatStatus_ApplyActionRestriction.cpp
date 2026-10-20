#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088474; symbol: func_02088474; size: 0x84.
void CombatStatus_ApplyActionRestriction(char *p,unsigned int mode,unsigned int op){p[0x21]=0;*(unsigned int *)(p+24)&=~32;*(unsigned int *)(p+20)&=~0x80000;*(unsigned short *)(p+34)&=~0x3c;*(unsigned int *)(p+20)&=~0x800000;p[36]=0;if(op==0x1fc||op==0x20f){*(unsigned int *)(p+20)&=~0x1000000;p[36]=0;}*(unsigned int *)(p+20)|=0x80000;*(unsigned short *)(p+34)=(*(unsigned short *)(p+34)&~0x3c)|((mode<<28)>>26);}
}
