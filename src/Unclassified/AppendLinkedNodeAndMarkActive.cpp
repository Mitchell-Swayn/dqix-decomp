#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020469B4; symbol: func_020469b4; size: 0x44.
void AppendLinkedNodeAndMarkActive(unsigned int *p,unsigned int n){if(p[0]&&p[1]){*(unsigned int *)(p[1]+4)=n;p[1]=n;*(unsigned int *)(n+4)=0;}else{p[0]=n;p[1]=n;*(unsigned int *)(n+4)=0;}*(unsigned int *)(n+4)=0;*(unsigned char *)(n+2)=1;}
}
