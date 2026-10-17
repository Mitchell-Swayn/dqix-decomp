#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020DA22C; symbol: func_020da22c; size: 0x18.
void InvalidateWords0And8AndClearByte4(unsigned int *p){p[2]=-1;p[0]=-1;*(char *)(p+1)=0;}
}
