#include <globaldefs.h>
ARM
struct Count{unsigned low:9;signed value:3;unsigned high:20;};
// Original: arm9/main @ 0x02087A48; symbol: func_02087a48; size: 0x54.
extern "C" bool TestDirectionalCountLimitUnlessDisabled(unsigned char* p,int reverse){if(*(unsigned*)(p+20)&1)return false;if(!reverse){int n=((Count*)(p+88))->value;if(n<2)return true;}else{if(-2<((Count*)(p+88))->value)return true;}return false;}
