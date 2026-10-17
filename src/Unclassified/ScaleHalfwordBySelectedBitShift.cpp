#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0204AA48; symbol: func_0204aa48; size: 0x1C.
int ScaleHalfwordBySelectedBitShift(char *p){int shift=5;if(*(unsigned char *)(p+10))shift=6;return *(short *)(p+4)<<shift;}
}
