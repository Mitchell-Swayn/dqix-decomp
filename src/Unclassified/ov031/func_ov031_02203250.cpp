#include <globaldefs.h>
ARM
extern "C" unsigned int data_02111304[];

// Original: arm9/ov031 @ 0x02203250; symbol: func_ov031_02203250; size: 0x20.
extern "C" void func_ov031_02203250(void) {
    unsigned int *pointer = *(unsigned int **)(data_02111304[1] + 0xa4);
    if (pointer != 0)
        *pointer = 0;
}
