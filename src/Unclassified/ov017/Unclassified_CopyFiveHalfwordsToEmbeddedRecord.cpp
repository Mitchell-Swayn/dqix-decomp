#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021BD35C; symbol: func_ov017_021bd35c; size: 0x30.
extern "C" void Unclassified_CopyFiveHalfwordsToEmbeddedRecord(void *destination, const unsigned short *source) {
    *(unsigned short *)((unsigned char *)destination + 0x150) = source[0];
    *(unsigned short *)((unsigned char *)destination + 0x152) = source[1];
    *(unsigned short *)((unsigned char *)destination + 0x154) = source[2];
    *(unsigned short *)((unsigned char *)destination + 0x156) = source[3];
    *(unsigned short *)((unsigned char *)destination + 0x158) = source[4];
}
