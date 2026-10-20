#include <globaldefs.h>
ARM
extern "C" void Graphics_ClearAndDispatchOffsetRecord(void *);
extern "C" void Window_ClearResourceBuffers(unsigned char *);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void *);
extern "C" void ResetFlaggedSelectedResourceEntry(void *);

// Original: arm9/ov023 @ 0x021EB4B8; symbol: Graphics_CleanupActiveObjectResourceBlock; size: 0x3C.
// Runs cleanup only when byte +0x431 is nonzero: invokes the object cleanup helper, clears/processes/resets the resource block at +0xc4, then invokes the final object helper.
extern "C" void Graphics_CleanupActiveObjectResourceBlock(void *object) {
    unsigned char *bytes = (unsigned char *)object;
    if (bytes[0x431] == 0) return;
    Graphics_ClearAndDispatchOffsetRecord(object);
    Window_ClearResourceBuffers(bytes + 0xc4);
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(bytes + 0xc4);
    Graphics_ResetCountedThirtyTwoByteTransfers(bytes + 0xc4);
    ResetFlaggedSelectedResourceEntry(object);
}
