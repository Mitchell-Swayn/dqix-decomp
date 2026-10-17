#include <globaldefs.h>
ARM

extern "C" unsigned char *FindTwoHundredTwentyFourByteRecordByByteKey(unsigned char *, unsigned int);
extern "C" bool IsKeyedRecordByteFlagBitFiveClear(void *, int);

// Original: arm9/ov006 @ 0x02158080; symbol: func_ov006_02158080; size: 0x38.
extern "C" int Unclassified_HasKeyedRecordWithFlagBitFiveClear(unsigned char *records, unsigned int key) {
    if (FindTwoHundredTwentyFourByteRecordByByteKey(records, key) != 0 &&
        IsKeyedRecordByteFlagBitFiveClear(records, key)) {
        return 1;
    }
    return 0;
}
