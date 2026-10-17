#include <globaldefs.h>
ARM
extern "C" void ClearEachIndexedEntryResource(unsigned char *object);
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *object);
extern "C" void func_0205da88(void *object, int first, int second, int third);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void *object);
extern "C" void func_ov003_0216acf0(void *object);
extern "C" void func_ov003_0216a880(void *object);
// Original: arm9/ov003 @ 0x02168560; symbol: func_ov003_02168560; size: 0x48.
extern "C" void GameState_ResetIndexedTransferResources(void *state) {
    unsigned char *object = (unsigned char *)state + 0xe4;
    ClearEachIndexedEntryResource(object);
    ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(object);
    func_0205da88(object, 1, 2, 1);
    Graphics_ResetCountedThirtyTwoByteTransfers(object);
    func_ov003_0216acf0(state);
    func_ov003_0216a880(state);
}
