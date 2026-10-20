#include <globaldefs.h>
struct Bits { unsigned short low:15; unsigned short high:1; };
// Original: arm9/main @ 0x0203402C; symbol: func_0203402c; size: 0x18.
extern "C" ARM bool GameObject_IsMovementPauseActive(char* p) { return ((Bits*)(p+0xc4))->low != 0; }
