#include <globaldefs.h>
ARM
extern "C" unsigned* data_ov031_02290d10;
extern "C" void func_ov031_0223e2c0(unsigned, unsigned);
extern "C" unsigned Unclassified_InvokeHelperWithZeroFifthArgument(unsigned, unsigned, unsigned, unsigned);
extern "C" void IncrementGlobalCounterAndNotifyAtEight();
// Original: arm9/ov031 @ 0x02237E58; symbol: func_ov031_02237e58; size: 0x44.
extern "C" void CreateSharedDisplayResource() {
    func_ov031_0223e2c0(0, data_ov031_02290d10[5]);
    data_ov031_02290d10[5] = Unclassified_InvokeHelperWithZeroFifthArgument(1, (unsigned)IncrementGlobalCounterAndNotifyAtEight, 0, 0x78);
}
