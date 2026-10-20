#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0203E03C; symbol: func_0203e03c; size: 0x30.
int ActorPool_FindEmptySlot(unsigned int *p){for(int i=0;i<32;i++)if(*(unsigned int *)((char *)(p+i)+12)==0)return i;return -1;}
}
