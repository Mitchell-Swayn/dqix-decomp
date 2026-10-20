#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
// Original: arm9/ov025 @ 0x021DCD5C; symbol: func_ov025_021dcd5c; size: 0x3C.
extern "C" void Resource_ResetPendingAndStatusFields(void *p) {
    char *bytes = (char *)p;
    bytes[0x6e4d] = 0;
    bytes[0x6e4c] = 0;
    memset(bytes + 0x6ef0, -1, 10);
    *(unsigned short *)(bytes + 0x6efa) = 0;
}
