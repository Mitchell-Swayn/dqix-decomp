#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0203E074; symbol: func_0203e074; size: 0x2C.
void ClearBuffer9EAndFields1DEAnd1E4(char *p){memset(p+0x9e,0,0x140);*(short *)(p+0x1de)=0;*(int *)(p+0x1e4)=0;}
}
