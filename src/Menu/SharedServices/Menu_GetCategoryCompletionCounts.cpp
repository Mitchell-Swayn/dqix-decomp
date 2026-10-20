#include <globaldefs.h>
ARM
// Original: arm9/ov004 @ 0x021546C0; symbol: FindSixByteRecordByHalfwordPairAndCopyBytes; size: 0x58.
// Searches twenty six-byte records for two matching signed halfwords, then copies the record bytes at +4 and +5 to the caller outputs.
extern "C" void Menu_GetCategoryCompletionCounts(const unsigned char *records, short a, short b, unsigned char *outA, unsigned char *outB) {
    for (unsigned char i = 0; i < 20; ++i) {
        const unsigned char *record = records + i * 6;
        if (*(short *)record == a && *(short *)(record + 2) == b) {
            *outA = record[4];
            *outB = record[5];
            return;
        }
    }
}
