#include <globaldefs.h>
#pragma optimization_level 4
extern "C" void func_020c6914(unsigned);
// Original: arm9/main @ 0x020C51A4; symbol: func_020c51a4; size: 0x1C.
extern "C" ARM void Graphics_SubmitGeometryCommand25(unsigned v){*(volatile unsigned*)0x04000400=25;func_020c6914(v);}
