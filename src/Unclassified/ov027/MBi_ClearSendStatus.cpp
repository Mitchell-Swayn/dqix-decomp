#include <globaldefs.h>
ARM
extern unsigned char data_ov027_021dd940[];
// Original: arm9/ov027 @ 0x021DAE1C; symbol: func_ov027_021dae1c; size: 0x24.
extern "C" void MBi_ClearSendStatus(void) {
    data_ov027_021dd940[0x25] = 0;
    data_ov027_021dd940[0x26] = 0;
    data_ov027_021dd940[0x27] = 0;
    data_ov027_021dd940[0x28] = 0;
    data_ov027_021dd940[0x29] = 0;
}
