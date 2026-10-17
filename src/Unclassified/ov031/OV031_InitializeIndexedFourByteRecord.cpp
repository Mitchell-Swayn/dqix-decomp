#include <globaldefs.h>
extern "C" unsigned char *Memory_AllocateZeroedBlock(unsigned, unsigned);
// Original: arm9/ov031 @ 0x0223BEB8; symbol: func_ov031_0223beb8; size: 0x34.
extern "C" void OV031_InitializeIndexedFourByteRecord(unsigned index) {
    unsigned char *record = Memory_AllocateZeroedBlock(((index + 1) << 2) + 8, 4);
    *(unsigned short *)record = (unsigned short)(index + 1);
    record[2] = 0;
    record[3] = 0;
}
