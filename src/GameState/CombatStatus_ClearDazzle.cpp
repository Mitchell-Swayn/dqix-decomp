#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088874; symbol: func_02088874; size: 0x1C.
void CombatStatus_ClearDazzle(char *p){*(unsigned int *)(p+20)&=~64;p[0x5f]=0;p[0x82]=0;}
}
