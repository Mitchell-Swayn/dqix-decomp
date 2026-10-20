#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0202BCBC; symbol: func_0202bcbc; size: 0x3C.
int Network_FindWirelessSlotByMemberId(signed char *p,int key){int i=0;for(;i<16;i++)if(*((signed char *)(p+i)+0x1038)==key)break;if(i==16)return -1;return (signed char)i;}
}
