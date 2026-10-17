#include <globaldefs.h>
ARM
extern "C" unsigned int ReadCountByteWhenBothOwnerPointersSet(char *);
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(void *, int);
extern "C" void ClearEachIndexedEntryResource(unsigned char *);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void *);
extern "C" void ResetEachIndexedEntryResource(void *);
// Original: arm9/ov023 @ 0x021D8B6C; symbol: func_ov023_021d8b6c; size: 0x48.
extern "C" void Graphics_ResetOwnedResourceBundle(void *p) {
    void *state = (char *)p + 0x20;
    if (ReadCountByteWhenBothOwnerPointersSet((char *)state))
        Object_ResetSelectionAndApplyConfiguredMode(state, 1);
    ClearEachIndexedEntryResource((unsigned char *)state);
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(state);
    Graphics_ResetCountedThirtyTwoByteTransfers(state);
    ResetEachIndexedEntryResource(state);
}
