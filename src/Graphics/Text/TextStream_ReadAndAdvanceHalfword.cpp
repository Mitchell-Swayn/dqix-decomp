#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020B2A58; symbol: func_020b2a58; size: 0x14.
unsigned int TextStream_ReadAndAdvanceHalfword(unsigned short **p){unsigned short *cursor=*p;unsigned int v=*cursor++;*p=cursor;return v;}
}
