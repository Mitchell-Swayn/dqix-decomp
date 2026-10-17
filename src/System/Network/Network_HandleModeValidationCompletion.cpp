#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void SetGlobalValueExceptModesNineAndTen(void);
extern "C" int WriteSharedFieldC8UnderIRQProtection(unsigned int);
extern "C" unsigned int data_021015a0[];
// Original: arm9/main @ 0x0202DB08; symbol: func_0202db08; size: 0x5C.
extern "C" void Network_HandleModeValidationCompletion(int param_1) {
    if (*(unsigned short *)(param_1 + 2) != 0) {
        SetGlobalValueExceptModesNineAndTen();
        data_021015a0[4] = 10;
        return;
    }
    if (WriteSharedFieldC8UnderIRQProtection(data_021015a0[16]) != 0) {
        SetGlobalValueExceptModesNineAndTen();
        data_021015a0[4] = 10;
        return;
    }
    data_021015a0[4] = 1;
}
