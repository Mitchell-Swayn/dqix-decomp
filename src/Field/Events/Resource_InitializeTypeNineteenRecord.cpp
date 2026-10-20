#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);
// Original: arm9/ov017 @ 0x021B2F64; symbol: func_ov017_021b2f64; size: 0x48.
extern "C" void Resource_InitializeTypeNineteenRecord(signed char *p) {
    LinkedQueue_InitializeNodeStatus(p);
    p[0] = 0x13;
    *(short *)(p + 8) = -1;
    p[0xa] = 0;
    p[0xb] = 0;
    *(int *)(p + 0xc) = 0;
    for (int i = 0; i < 14; i++) *(int *)(p + 0x10 + i * 4) = -1;
}
