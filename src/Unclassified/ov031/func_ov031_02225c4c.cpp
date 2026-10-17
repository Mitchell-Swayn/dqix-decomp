#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02250c00;
// Original: arm9/ov031 @ 0x02225C4C; symbol: func_ov031_02225c4c; size: 0x14.
extern "C" void func_ov031_02225c4c(unsigned char value) {
    *((unsigned char *)(*(unsigned int *)&data_ov031_02250c00) + 0x67) = value;
}
