#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020DDE64; symbol: func_020dde64; size: 0x20.
void ClearRecordWordsAndByteFlags(char *p){p[4]=0;*(int *)(p+24)=0;*(int *)(p+28)=0;*(int *)(p+16)=0;*(int *)(p+20)=0;p[36]=0;}
}
