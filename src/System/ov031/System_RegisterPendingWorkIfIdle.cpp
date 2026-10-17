#include <globaldefs.h>
extern "C" void OSi_ReferSymbol(const void*);
extern "C" unsigned data_ov031_022496a4;
extern "C" void func_ov031_02204e38();
extern "C" int func_ov031_02204df8();
// Original: arm9/ov031 @ 0x02204DBC; symbol: func_ov031_02204dbc; size: 0x3C.
extern "C" int System_RegisterPendingWorkIfIdle(unsigned value) {
    OSi_ReferSymbol((const void*)0x02000c1c);
    if (data_ov031_022496a4) return 0;
    data_ov031_022496a4 = value;
    func_ov031_02204e38();
    return func_ov031_02204df8();
}
