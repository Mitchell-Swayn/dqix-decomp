#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02089144; symbol: func_02089144; size: 0x1C.
void CombatantState_ClearRoughAndTumble(char *p){*(unsigned int *)(p+24)&=~0x400;p[0x79]=0;p[0x9c]=0;}
}
