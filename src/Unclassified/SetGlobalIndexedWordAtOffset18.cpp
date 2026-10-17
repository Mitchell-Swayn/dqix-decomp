#include <globaldefs.h>
extern "C" { extern unsigned int *data_021142e0[];
// Original: arm9/main @ 0x020D404C; symbol: func_020d404c; size: 0x18.
void SetGlobalIndexedWordAtOffset18(int i,unsigned int v){unsigned int *p=data_021142e0[1];*(unsigned int *)((char *)(p+i)+0x18)=v;} }
