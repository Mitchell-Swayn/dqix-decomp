#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088598; symbol: func_02088598; size: 0x1C.
void ClearField14Flag2AndField22LowBits(char *p){*(unsigned int *)(p+20)&=~2;*(unsigned short *)(p+34)&=~3;}
}
