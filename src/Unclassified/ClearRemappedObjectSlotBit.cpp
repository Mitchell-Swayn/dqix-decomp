#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020D76D8; symbol: func_020d76d8; size: 0x24.
void ClearRemappedObjectSlotBit(char *p,int i){if(i>=0xc0)i-=0xbc;*(unsigned short *)(p+0xa26)&=~(1<<i);}
}
