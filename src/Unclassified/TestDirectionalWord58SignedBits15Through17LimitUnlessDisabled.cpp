#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02087C30; symbol: func_02087c30; size: 0x54.
int TestDirectionalWord58SignedBits15Through17LimitUnlessDisabled(unsigned int *p,int dir){if(p[5]&1)return 0;if(dir==0){if(((int)(p[22]<<14)>>29)<2)return 1;}else if(-2<((int)(p[22]<<14)>>29))return 1;return 0;}
}
