#include <globaldefs.h>
#pragma optimization_level 4
extern "C" void func_020c6938(unsigned);
// Original: arm9/main @ 0x020C516C; symbol: func_020c516c; size: 0x1C.
extern "C" ARM void Graphics_WriteGeometryCommand22AndValue(unsigned value){*(volatile unsigned*)0x04000400=22;func_020c6938(value);}
