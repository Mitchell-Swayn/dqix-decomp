#include <globaldefs.h>
ARM
extern "C" void DispatchVariadicArgumentsThroughArgumentList(unsigned, unsigned, ...);
extern "C" unsigned char *data_ov031_02290cfc;
extern "C" unsigned char data_ov031_0224be50[];

// Original: arm9/ov031 @ 0x02236038; symbol: func_ov031_02236038; size: 0x44.
extern "C" void func_ov031_02236038(unsigned first) {
    unsigned char *state = data_ov031_02290cfc;
    unsigned char *arguments = state + 0x4cc;
    DispatchVariadicArgumentsThroughArgumentList(first,
        (unsigned)data_ov031_0224be50,
        arguments[0], arguments[1], arguments[2], arguments[3]);
}
