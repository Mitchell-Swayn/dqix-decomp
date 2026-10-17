#include <globaldefs.h>
ARM
extern "C" void ClearEachIndexedEntryResource(unsigned char *p);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *object);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void *object);
// Original: arm9/ov023 @ 0x021D8C60; symbol: func_ov023_021d8c60; size: 0x34.
extern "C" void Graphics_ClearInactiveResourceState(unsigned char* object) {
    unsigned char state = object[0x11a];
    if (state != 0 && state != 3) {
        ClearEachIndexedEntryResource(object + 0x20);
        ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(object + 0x20);
        Graphics_ResetCountedThirtyTwoByteTransfers(object + 0x20);
    }
}
