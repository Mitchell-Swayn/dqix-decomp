#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov027_021dd940[];
extern "C" void MBi_ClearSendStatus(void);
// Original: arm9/ov027 @ 0x021DADF0; symbol: func_ov027_021dadf0; size: 0x2C.
extern "C" void Network_InitializeSendGameInfoStatus(void) {
    *(unsigned int *)(data_ov027_021dd940 + 0x18) = 0;
    *(unsigned int *)(data_ov027_021dd940 + 0x1C) = 0;
    data_ov027_021dd940[0x24] = 1;
    *(unsigned int *)(data_ov027_021dd940 + 0x14) = 0;
    MBi_ClearSendStatus();
}
