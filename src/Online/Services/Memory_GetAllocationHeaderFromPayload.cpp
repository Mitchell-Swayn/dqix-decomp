#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02211B20; symbol: Memory_GetAllocationHeaderFromPayload; size: 0x8.
// Moves backward 0x20 bytes from the supplied payload to its allocation header, as used by shared-string dispatch.
extern "C" void *Memory_GetAllocationHeaderFromPayload(void *payload) {
    return (unsigned char *)payload - 0x20;
}
