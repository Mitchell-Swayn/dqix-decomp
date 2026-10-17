#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void ReleaseIndexedRecordAndInvalidateIndex(void);
extern "C" void ClearFiveWordsAndInvalidateHalfword14(unsigned int);
// Original: arm9/main @ 0x0203C0F0; symbol: func_0203c0f0; size: 0x18.
extern "C" void Graphics_ResetAndApplyGlobalConfiguration(unsigned int value) {
    ReleaseIndexedRecordAndInvalidateIndex();
    ClearFiveWordsAndInvalidateHalfword14(value);
}
