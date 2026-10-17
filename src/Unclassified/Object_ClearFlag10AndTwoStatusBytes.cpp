#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088390; symbol: func_02088390; size: 0x1C.
void Object_ClearFlag10AndTwoStatusBytes(char *p){*(unsigned int *)(p+0x14)&=~16;*(unsigned char *)(p+0x5d)=0;*(unsigned char *)(p+0x80)=0;}
}
