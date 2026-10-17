#include <globaldefs.h>
extern "C" unsigned char data_ov031_02290d04[];
extern "C" void func_ov031_02236f88();
extern "C" int Unclassified_InvokeHelperWithZeroFifthArgument(int, void (*)(), int, int);
// Original: arm9/ov031 @ 0x02236E60; symbol: func_ov031_02236e60; size: 0x40.
extern "C" void OV031_InitializeGlobalCallback(void) {
    unsigned char *state = *(unsigned char **)(data_ov031_02290d04 + 4);
    state[0x18] = 1;
    int token = Unclassified_InvokeHelperWithZeroFifthArgument(0, func_ov031_02236f88, 0, 0x78);
    *(int *)(*(unsigned char **)(data_ov031_02290d04 + 4) + 0x14) = token;
}
