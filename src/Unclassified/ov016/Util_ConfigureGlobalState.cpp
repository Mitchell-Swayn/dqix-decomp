#include <globaldefs.h>
ARM
struct GlobalState {
    int field0;
    int field4;
    char padding8[4];
    int fieldC;
    int field10;
    char padding14[12];
    int field20;
};
extern "C" GlobalState data_ov016_0219d1c0;
// Original: arm9/ov016 @ 0x0218FCAC; symbol: func_ov016_0218fcac; size: 0x28.
extern "C" void Util_ConfigureGlobalState(int a0, int a1) {
    data_ov016_0219d1c0.field10 = a0;
    data_ov016_0219d1c0.fieldC = a1 & ~3;
    data_ov016_0219d1c0.field4 = 0;
    data_ov016_0219d1c0.field0 = 0;
    data_ov016_0219d1c0.field20 = 0;
}
