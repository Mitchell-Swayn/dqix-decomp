#include <globaldefs.h>
ARM
typedef void (*Apply)(unsigned,unsigned);extern "C" Apply data_020f2c04[][2];extern "C" Apply data_020f2be4[];
// Original: arm9/main @ 0x020E2C7C; symbol: func_020e2c7c; size: 0x48.
extern "C" void DispatchTwoPairsThroughIndexedFunctionTables(unsigned char* p){data_020f2c04[p[1]][p[2]](*(unsigned*)(p+4),*(unsigned*)(p+8));data_020f2be4[p[1]](*(unsigned*)(p+12),*(unsigned*)(p+16));}
