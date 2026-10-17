#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c7c4(unsigned);
extern "C" volatile unsigned char data_ov031_02250bac[];
// Original: arm9/ov031 @ 0x02223440; symbol: func_ov031_02223440; size: 0x38.
extern "C" int Overlay_ProcessPendingFlag(void) {
    if (data_ov031_02250bac[0] == 0) return 0;
    func_ov031_0223c7c4(1);
    data_ov031_02250bac[0] = 0;
    return 1;
}
