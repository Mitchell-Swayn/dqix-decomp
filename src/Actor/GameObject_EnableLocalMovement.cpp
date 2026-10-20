#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020340F4; symbol: func_020340f4; size: 0x10.
extern "C" void GameObject_EnableLocalMovement(unsigned char* p) { p[0xc1] &= ~4; }
