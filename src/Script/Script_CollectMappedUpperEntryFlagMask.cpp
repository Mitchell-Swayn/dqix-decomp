#include <globaldefs.h>
extern "C" {
int BitArray_ReadNonnegativeIndexMask(char *,char *,int);
// Original: arm9/main @ 0x0206E384; symbol: func_0206e384; size: 0x50.
unsigned short Script_CollectMappedUpperEntryFlagMask(char *p){unsigned short result=0;for(int i=0;i<16;i++)if(BitArray_ReadNonnegativeIndexMask(p,p+0x8c,i+0xc02))result|=1<<i;return result;}
}
