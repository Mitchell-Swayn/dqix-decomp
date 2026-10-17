#include <globaldefs.h>
ARM
extern "C" void DispatchVariadicArgumentsThroughArgumentList(unsigned a, unsigned b, ...);
extern "C" unsigned char* data_ov031_02290cfc;
extern "C" unsigned char data_ov031_0224be50[];
// Original: arm9/ov031 @ 0x02235F70; symbol: func_ov031_02235f70; size: 0x40.
extern "C" void Graphics_DispatchCurrentFourByteValues(unsigned a) {
    unsigned char* state = data_ov031_02290cfc;
    DispatchVariadicArgumentsThroughArgumentList(a, (unsigned)data_ov031_0224be50,
        state[0x4f0], state[0x4f1], state[0x4f2], state[0x4f3]);
}
