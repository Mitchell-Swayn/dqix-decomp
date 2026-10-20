#include <globaldefs.h>
ARM

extern "C" unsigned char *TextCanvas_FindDisplayPartByKey(unsigned char *, unsigned int);
extern "C" bool TextCanvas_IsDisplayPartVisible(void *, int);

// Original: arm9/ov006 @ 0x02158080; symbol: func_ov006_02158080; size: 0x38.
extern "C" int KrakPot_IsDisplayPartPresentAndFlagFiveClear(unsigned char *records, unsigned int key) {
    if (TextCanvas_FindDisplayPartByKey(records, key) != 0 &&
        TextCanvas_IsDisplayPartVisible(records, key)) {
        return 1;
    }
    return 0;
}
