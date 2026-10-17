#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E3084; symbol: func_ov025_021e3084; size: 0x64.
extern "C" void InitializeObjectStateFields(void *state) {
    unsigned char *bytes = (unsigned char *)state;
    *(unsigned int *)(bytes + 0x00) = 0;
    *(unsigned int *)(bytes + 0x04) = 0;
    *(unsigned int *)(bytes + 0x08) = 0;
    *(unsigned int *)(bytes + 0x0c) = 0;
    *(unsigned int *)(bytes + 0x10) = 0;
    *(short *)(bytes + 0x14) = -1;
    *(short *)(bytes + 0x16) = -1;
    *(unsigned int *)(bytes + 0x18) = 0;
    *(short *)(bytes + 0x1c) = -1;
    *(short *)(bytes + 0x1e) = -1;
    *(unsigned int *)(bytes + 0x20) = 0;
    *(short *)(bytes + 0x24) = 0;
    *(short *)(bytes + 0x26) = 0;
    *(short *)(bytes + 0x28) = 0;
    *(short *)(bytes + 0x2c) = 0;
    *(short *)(bytes + 0x2a) = 0;
    *(short *)(bytes + 0x32) = 0;
    *(short *)(bytes + 0x30) = 0;
    *(short *)(bytes + 0x2e) = 0;
    bytes[0x34] = 0;
    bytes[0x35] = 0;
    bytes[0x38] = 0;
}
