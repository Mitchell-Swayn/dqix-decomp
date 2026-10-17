#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020BC16C; symbol: func_020bc16c; size: 0x14.
void WritePresentIndirectWordIndex64(unsigned char *volatile *p,unsigned char v){if(*p)(*p)[64]=v;}
}
