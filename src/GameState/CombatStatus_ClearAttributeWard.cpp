#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088674; symbol: func_02088674; size: 0x28.
void CombatStatus_ClearAttributeWard(char *p){*(unsigned int *)(p+24)&=~128;*(unsigned short *)(p+34)&=~0xe00;p[0x6a]=0;p[0x8d]=0;}
}
