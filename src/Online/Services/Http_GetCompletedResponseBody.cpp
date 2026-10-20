#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022412E8; symbol: Network_ReadValidatedRecordValueAndOutputField18; size: 0x24.
// Requires nonzero words at offsets 4 and 8, copies offset 0x18 to the output, and returns the word at offset 4.
extern "C" int Http_GetCompletedResponseBody(unsigned char *p, unsigned int *out) {
    if (*(unsigned int *)(p + 8) == 0 || *(unsigned int *)(p + 4) == 0) return -1;
    *out = *(unsigned int *)(p + 0x18);
    return *(int *)(p + 4);
}
