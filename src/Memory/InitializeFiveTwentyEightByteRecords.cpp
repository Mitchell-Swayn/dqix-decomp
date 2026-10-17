#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original: arm9/main @ 0x0206DE40; symbol: func_0206de40; size: 0x88.
void InitializeFiveTwentyEightByteRecords(unsigned char *p){for(int i=0;i<5;i++){unsigned char *q=p+i*28;q[0]=1;q[1]=1;q[2]=1;memset(q+3,0,4);memset(q+8,0,8);memset(q+16,0,4);memset(q+20,0,8);}}
}
