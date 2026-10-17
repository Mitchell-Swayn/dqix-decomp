#include <globaldefs.h>
extern "C" unsigned data_ov031_0224f670[];
extern "C" unsigned data_ov031_0224b114[];
extern "C" unsigned func_ov031_02220af0();
extern "C" void func_ov031_0221fcb4();
extern "C" void func_ov031_02222af0();
// Original: arm9/ov031 @ 0x02220ED4; symbol: func_ov031_02220ed4; size: 0x38.
extern "C" THUMB void Ov031_UpdateModeFromStatus() {
    unsigned status = func_ov031_02220af0();
    data_ov031_0224f670[0x78 / 4] = status;
    func_ov031_0221fcb4();
    if (status == 1) data_ov031_0224f670[0x38 / 4] = 6;
    else data_ov031_0224f670[0x38 / 4] = 7;
    data_ov031_0224b114[0xc / 4] = 0xffffffff;
    func_ov031_02222af0();
}
