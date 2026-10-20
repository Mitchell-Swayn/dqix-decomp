#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215CA90; symbol: func_ov003_0215ca90; size: 0x14.
extern "C" void Inn_SetPricePerGuestAndComputeTotal(void *object, unsigned value) {
    *(unsigned *)((char *)object + 0x3c8) = value;
    *(unsigned *)((char *)object + 0x3cc) = value * *(unsigned char *)((char *)object + 0x3c3);
}
