#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02087B14; symbol: func_02087b14; size: 0x28.
void ClearField14Flag2000AndField58FlagE00AndBytes71And94(char *p){*(unsigned int *)(p+0x14)&=~0x2000;*(unsigned int *)(p+0x58)&=~0xe00;*(unsigned char *)(p+0x71)=0;*(unsigned char *)(p+0x94)=0;}
}
