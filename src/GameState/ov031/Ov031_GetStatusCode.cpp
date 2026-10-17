#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02250c0c;
// Original: arm9/ov031 @ 0x022275A0; symbol: func_ov031_022275a0; size: 0x40.
extern "C" unsigned int Ov031_GetStatusCode(void) {
    unsigned char status = data_ov031_02250c0c;
    if (status == 6) return 0x38;
    if (status == 1 && ((*(unsigned int *)((char *)&data_ov031_02250c0c + 8) >> 4) & 2) == 0) return 0x37;
    return (status + 0x31) & 0xff;
}
