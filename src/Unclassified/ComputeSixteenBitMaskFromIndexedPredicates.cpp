#include <globaldefs.h>
extern "C" {
int ReadNonnegativeIndexedBit(char *,char *,int);
// Original: arm9/main @ 0x0206E384; symbol: func_0206e384; size: 0x50.
unsigned short ComputeSixteenBitMaskFromIndexedPredicates(char *p){unsigned short result=0;for(int i=0;i<16;i++)if(ReadNonnegativeIndexedBit(p,p+0x8c,i+0xc02))result|=1<<i;return result;}
}
