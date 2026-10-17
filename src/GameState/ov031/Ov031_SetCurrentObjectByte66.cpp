#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_02250c00;
// Original: arm9/ov031 @ 0x02225C38; symbol: func_ov031_02225c38; size: 0x14.
extern "C" void Ov031_SetCurrentObjectByte66(unsigned char value) {
    data_ov031_02250c00[0x66] = value;
}
