#include <globaldefs.h>
ARM
extern "C" unsigned CRC32_ComputeThreeWordHeaderChecksum(const void *data);
// Original: arm9/ov031 @ 0x02211658; symbol: func_ov031_02211658; size: 0x20.
extern "C" void Network_ClearFlagAndStoreHeaderChecksum(void *object) {
    *(unsigned int *)((char *)object + 0x20) &= ~1u;
    unsigned int checksum = CRC32_ComputeThreeWordHeaderChecksum(object);
    *(unsigned int *)((char *)object + 0x3c) = checksum;
}
