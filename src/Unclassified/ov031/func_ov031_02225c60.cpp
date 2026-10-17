#include <globaldefs.h>
ARM
extern "C" char *data_ov031_02250c00;
// Original: arm9/ov031 @ 0x02225C60; symbol: func_ov031_02225c60; size: 0x14.
extern "C" void func_ov031_02225c60(int a0) {
    *(unsigned char *)(data_ov031_02250c00 + 0x68) = a0;
}
