#include <globaldefs.h>
ARM
extern "C" unsigned int ReadOverlayControlSecondWord(void);
extern "C" void SetThreeRecordHalfwordFields(unsigned char *record, short a, unsigned short b, unsigned short c);
// Original: arm9/ov025 @ 0x021E821C; symbol: func_ov025_021e821c; size: 0x2C.
extern "C" unsigned int Unclassified_CopyThreeObjectFieldsToOverlayRecord(void *object) {
    register short a = *(short *)((unsigned char *)object + 8);
    register unsigned short b = *(unsigned short *)((unsigned char *)object + 0xA);
    register unsigned short c = *(unsigned short *)((unsigned char *)object + 0xC);
    unsigned char *record = (unsigned char *)ReadOverlayControlSecondWord();
    SetThreeRecordHalfwordFields(record, a, b, c);
    return 1;
}
