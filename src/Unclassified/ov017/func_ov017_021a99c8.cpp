#include <globaldefs.h>
ARM
extern "C" void func_ov017_021a9714(void *);
// Original: arm9/ov017 @ 0x021A99C8; symbol: func_ov017_021a99c8; size: 0x14.
extern "C" void func_ov017_021a99c8(void *p) { *((unsigned char *)p + 1) = 1; func_ov017_021a9714(p); }
