#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0203DCE4; symbol: func_0203dce4; size: 0x2C.
unsigned int *ActorPool_GetActiveSlot(unsigned int **p,unsigned int i){if(i>=32)return 0;unsigned int *v=*(unsigned int **)((char *)(p+i)+12);if(!v)return v;if(*v&0x8000)v=0;return v;}
}
