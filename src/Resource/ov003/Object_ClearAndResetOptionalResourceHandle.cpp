#include <globaldefs.h>
ARM
extern "C" void ClearEachIndexedEntryResource(unsigned char *);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *);
extern "C" void func_0205da88(void *, int, int, int);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void *);
extern "C" void func_ov003_0217e100(void *);
// Original: arm9/ov003 @ 0x0217DA48; symbol: func_ov003_0217da48; size: 0x5C.
extern "C" void Object_ClearAndResetOptionalResourceHandle(unsigned char *owner) {
    if (*(void **)(owner + 0x90) != 0 && (*(signed char *)(owner + 4) == 2 || *(signed char *)(owner + 5) == 0)) {
        ClearEachIndexedEntryResource(*(unsigned char **)(owner + 0x90));
        ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(*(void **)(owner + 0x90));
        func_0205da88(*(void **)(owner + 0x90), 2, 1, 1);
        Graphics_ResetCountedThirtyTwoByteTransfers(*(void **)(owner + 0x90));
    }
    func_ov003_0217e100(owner);
}
