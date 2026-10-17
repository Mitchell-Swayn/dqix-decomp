#include <globaldefs.h>
ARM
extern "C" unsigned int data_02111304[];
// Original: arm9/ov031 @ 0x02203270; symbol: func_ov031_02203270; size: 0x18.
extern "C" void func_ov031_02203270(void *p) {
    *(unsigned int *)((unsigned char *)p + 0xa4) = *(unsigned int *)(data_02111304[1] + 0xa4);
}
