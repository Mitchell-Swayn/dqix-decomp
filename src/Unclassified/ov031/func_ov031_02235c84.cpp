#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290cfc[];
// Original: arm9/ov031 @ 0x02235C84; symbol: func_ov031_02235c84; size: 0x14.
extern "C" void func_ov031_02235c84(unsigned char value) {
    *(unsigned char *)((char *)*(void **)data_ov031_02290cfc + 0x4f5) = value;
}
