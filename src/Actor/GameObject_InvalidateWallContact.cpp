#include <globaldefs.h>
struct Bits { unsigned char low:6; unsigned char b6:1; unsigned char b7:1; };
// Original: arm9/main @ 0x02033F2C; symbol: func_02033f2c; size: 0x18.
extern "C" ARM void GameObject_InvalidateWallContact(char* p) { Bits* b=(Bits*)(p+0xe0); b->b6=0; b->b7=0; }
