#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020A28B0; symbol: func_020a28b0; size: 0x14.
void Camera_ClearFollowControlFlags(unsigned char *p,unsigned char mask){p[0x244]&=~mask;}
}
