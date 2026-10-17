#include <globaldefs.h>
ARM
extern "C" double Runtime_ComputeDoublePower(double, double);
struct State;
extern "C" void func_ov011_021848a0(State* self, unsigned value);
extern "C" volatile unsigned data_ov004_021707d8[];
// Original: arm9/ov004 @ 0x0215ADF8; symbol: func_ov004_0215adf8; size: 0xB0.
extern "C" int BuildSevenDigitValueAndAdvanceState(State *self) {
    *(int *)(((char *)data_ov004_021707d8[2]) + 0x78) = 0;
    for (int i = 0; i < 7; ++i) {
        int place = (int)Runtime_ComputeDoublePower(10.0, (double)i);
        char *record = ((char *)data_ov004_021707d8[2]);
        *(int *)(record + 0x78) += place * *(signed char *)(record + i + 0x3f);
    }
    *(unsigned char *)(((char *)data_ov004_021707d8[2]) + 0x6e) = 1;
    if (*(unsigned char *)(((char *)data_ov004_021707d8[2]) + 0x6f) == 1) func_ov011_021848a0(self, 0x39c);
    else func_ov011_021848a0(self, 0x6d);
    return 0;
}
