#include <globaldefs.h>
ARM
extern "C" bool TestNonnegativeIdentifierWithByteOverride(char *p);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
extern "C" char data_02109bf4[];
// Original: arm9/ov001 @ 0x0216376C; symbol: func_ov001_0216376c; size: 0x3C.
extern "C" unsigned int Unclassified_SetNestedFlagFromOverrideTest(void *output) {
    if (TestNonnegativeIdentifierWithByteOverride(data_02109bf4)) {
        SetNestedSecondWordForTypeThree(output, 1);
    } else {
        SetNestedSecondWordForTypeThree(output, 0);
    }
    return 1;
}
