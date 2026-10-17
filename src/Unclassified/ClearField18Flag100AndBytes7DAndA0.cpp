#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088D9C; symbol: func_02088d9c; size: 0x1C.
void ClearField18Flag100AndBytes7DAndA0(char *p){*(unsigned int *)(p+24)&=~0x100;p[0x7d]=0;p[0xa0]=0;}
}
