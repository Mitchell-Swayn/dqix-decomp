#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov027_021dd940[];
// Original: arm9/ov027 @ 0x021DB124; symbol: func_ov027_021db124; size: 0x30.
extern "C" void MBi_InitSendVolatBeacon(void) {
    *(unsigned short *)(*(unsigned char **)(data_ov027_021dd940 + 0x1c) + 0x4b0) = 1;
    data_ov027_021dd940[0x26] = (*(unsigned char **)(data_ov027_021dd940 + 0x1c))[0x4b4];
    data_ov027_021dd940[0x24] = 5;
}
