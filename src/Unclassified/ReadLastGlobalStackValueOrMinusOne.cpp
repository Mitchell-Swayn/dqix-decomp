#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
extern volatile unsigned char data_02109da4;extern signed char data_02109dae[];
// Original: arm9/main @ 0x020A1EB0; symbol: func_020a1eb0; size: 0x2C.
int ReadLastGlobalStackValueOrMinusOne(){int v;if(data_02109da4!=0)v=data_02109dae[data_02109da4-1];else v=-1;return v;}
}
