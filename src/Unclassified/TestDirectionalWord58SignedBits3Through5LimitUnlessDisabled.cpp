#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02087860; symbol: func_02087860; size: 0x54.
int TestDirectionalWord58SignedBits3Through5LimitUnlessDisabled(unsigned int *p,int dir){if(p[5]&1)return 0;if(dir==0){if(((int)(p[22]<<26)>>29)<2)return 1;}else if(-2<((int)(p[22]<<26)>>29))return 1;return 0;}
}
