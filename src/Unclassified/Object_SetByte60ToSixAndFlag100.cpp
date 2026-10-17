#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020888A4; symbol: func_020888a4; size: 0x20.
void Object_SetByte60ToSixAndFlag100(char *p){p[0x60]=6;p[0x83]=0;*(unsigned int *)(p+20)|=0x100;}
}
