#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02291e04[];
// Original: arm9/ov031 @ 0x02243418; symbol: func_ov031_02243418; size: 0x14.
extern "C" void Ov031_SetGlobalField30ToOne(void) {
    data_ov031_02291e04[12] = 1;
}
