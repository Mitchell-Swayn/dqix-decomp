#include <globaldefs.h>
ARM
struct Flags {signed int low:21;signed int mode:3;signed int high:8;};
// Original: arm9/main @ 0x02087E18; symbol: func_02087e18; size: 0x54.
extern "C" int TestDirectionalWord58SignedBits21Through23LimitUnlessDisabled(unsigned char* p,int flag) { if(*(unsigned int*)(p+20)&1)return 0;if(flag==0) { if(((Flags*)(p+88))->mode<2)return 1; }else if(-2<((Flags*)(p+88))->mode)return 1;return 0; }
