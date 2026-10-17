#include <globaldefs.h>
ARM
extern "C" void DispatchVariadicArgumentsThroughArgumentList(unsigned, unsigned, ...);
extern "C" unsigned int data_ov031_02290cfc;
extern "C" unsigned int data_ov031_0224be50;
// Original: arm9/ov031 @ 0x02235F30; symbol: func_ov031_02235f30; size: 0x40.
extern "C" void func_ov031_02235f30(unsigned arg) {
    unsigned char* p = (unsigned char*)data_ov031_02290cfc;
    DispatchVariadicArgumentsThroughArgumentList(arg, (unsigned)&data_ov031_0224be50,
        p[0x4c0], p[0x4c1], p[0x4c2], p[0x4c3]);
}
