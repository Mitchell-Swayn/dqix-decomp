#include <globaldefs.h>
ARM

extern "C" void InitializeFourWordsWithInvalidIndex(signed char *p);
extern "C" unsigned int data_ov017_021d8478;

// Original: arm9/ov017 @ 0x021C1350; symbol: func_ov017_021c1350; size: 0x44.
extern "C" void Unclassified_InitializeRecordWithType2E(unsigned char *record, unsigned char first, unsigned char second) {
    InitializeFourWordsWithInvalidIndex((signed char *)record);
    record[0] = 0x2e;
    data_ov017_021d8478 = 0;
    record[0x1c] = 0;
    record[0x1e] = first;
    record[0x1f] = second;
    record[0x1d] = 0xff;
}
