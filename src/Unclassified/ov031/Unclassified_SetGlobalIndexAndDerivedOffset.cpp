#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290ca0[];
extern "C" unsigned char data_ov031_02249054[];
extern "C" int Unclassified_FindOffsetWithinFourValues(int value);
extern "C" void func_ov031_022307fc(void);
// Original: arm9/ov031 @ 0x02230984; symbol: func_ov031_02230984; size: 0x30.
extern "C" void Unclassified_SetGlobalIndexAndDerivedOffset(unsigned char index) {
    data_ov031_02290ca0[0] = index;
    data_ov031_02290ca0[2] = (unsigned char)Unclassified_FindOffsetWithinFourValues(data_ov031_02249054[index]);
    func_ov031_022307fc();
}
