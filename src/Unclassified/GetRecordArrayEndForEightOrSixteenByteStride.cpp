#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020B0074; symbol: func_020b0074; size: 0x20.
char *GetRecordArrayEndForEightOrSixteenByteStride(unsigned short *p){if(p[1]&1)return *(char **)(p+2)+p[0]*16;return *(char **)(p+2)+p[0]*8;}
}
