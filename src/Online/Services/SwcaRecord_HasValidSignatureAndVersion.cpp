#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022115A4; symbol: func_ov031_022115a4; size: 0x2C.
extern "C" int SwcaRecord_HasValidSignatureAndVersion(void *header) {
    if (*(unsigned int *)((char *)header + 0x28) != 0x41435753)
        return 0;
    return *(unsigned int *)((char *)header + 0x2c) == 0x10000;
}
