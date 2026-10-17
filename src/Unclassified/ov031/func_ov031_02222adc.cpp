#include <globaldefs.h>
THUMB
#include <std_library_functions.h>
extern "C" unsigned char data_ov031_0224f7dc[];

// Original: arm9/ov031 @ 0x02222ADC; symbol: func_ov031_02222adc; size: 0x14.
extern "C" int func_ov031_02222adc(void *destination) {
    memcpy(destination, data_ov031_0224f7dc, 0xe8);
    return 1;
}
