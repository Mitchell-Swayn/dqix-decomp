#include <globaldefs.h>
ARM
extern "C" void DispatchVariadicArgumentsThroughArgumentList(unsigned, unsigned, ...);
extern "C" unsigned int data_ov031_02290cfc;
extern "C" unsigned int data_ov031_0224be50;
// Original: arm9/ov031 @ 0x02235FB0; symbol: func_ov031_02235fb0; size: 0x44.
extern "C" void Graphics_DispatchFourValuesAt4C4(unsigned value) {
    unsigned char *state = (unsigned char *)data_ov031_02290cfc;
    unsigned char *arguments = state + 0x4c4;
    DispatchVariadicArgumentsThroughArgumentList(value, (unsigned)&data_ov031_0224be50,
        arguments[0], arguments[1], arguments[2], arguments[3]);
}
