#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02048418; symbol: func_02048418; size: 0x30.
int GameObject_TestAndClearStatusMask(unsigned int **p,unsigned int mask){unsigned int *f=p[0x4c];unsigned int v=*f;if(!(mask&v))return 0;*f=(unsigned short)(v&~mask);return 1;}
}
