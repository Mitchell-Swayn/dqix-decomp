#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov001_02165880[];
// Original: arm9/ov001 @ 0x02162320; symbol: func_ov001_02162320; size: 0x18.
extern "C" void IncrementGlobalOffset28(void) {
    data_ov001_02165880[10] += 3;
}
