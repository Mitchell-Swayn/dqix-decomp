#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0209CBB8; symbol: func_0209cbb8; size: 0x14.
void Object_ClearInitialWordAndTwoBytes(unsigned int *p){p[0]=0;*(char *)(p+1)=0;*((char *)p+5)=0;}
}
