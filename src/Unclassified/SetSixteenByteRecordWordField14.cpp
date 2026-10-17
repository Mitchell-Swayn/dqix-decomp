#include <globaldefs.h>
extern "C" {
extern unsigned int **data_02110370;
// Original: arm9/main @ 0x020BD8D4; symbol: func_020bd8d4; size: 0x1C.
void SetSixteenByteRecordWordField14(int i,unsigned int v){unsigned int *p=data_02110370[0x21];*(unsigned int *)((char *)p+i*16+0x14)=v;}
}
