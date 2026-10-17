#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *);

// Original: arm9/ov017 @ 0x021AA3F4; symbol: func_ov017_021aa3f4; size: 0x28.
extern "C" void Unclassified_InitializeRecordType19AndClearThreeHalfwords(signed char *record) {
    InitializeFourWordsWithInvalidIndex(record);
    record[0] = 0x19;
    *(unsigned short *)(record + 8) = 0;
    *(unsigned short *)(record + 0x0a) = 0;
    *(unsigned short *)(record + 0x0c) = 0;
}
