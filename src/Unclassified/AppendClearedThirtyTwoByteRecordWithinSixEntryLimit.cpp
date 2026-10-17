#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0209BD40; symbol: func_0209bd40; size: 0x40.
void AppendClearedThirtyTwoByteRecordWithinSixEntryLimit(char *p,short v){int i=*(int *)(p+0xc0);if(i>=6)return;int offset=i*32;memset(p+offset,0,32);*(short *)(p+offset)=v;(*(int *)(p+0xc0))++;}
}
