#include <globaldefs.h>
ARM
extern "C" unsigned int data_02111304[];

// Original: arm9/ov031 @ 0x02203178; symbol: func_ov031_02203178; size: 0x18.
extern "C" void func_ov031_02203178(void) {
    *(unsigned int *)(data_02111304[1] + 0xa4) = 0;
}
