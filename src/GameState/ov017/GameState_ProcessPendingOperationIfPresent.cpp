#include <globaldefs.h>
ARM
extern "C" void func_ov017_021d4e38(void *object);
// Original: arm9/ov017 @ 0x021D4CCC; symbol: func_ov017_021d4ccc; size: 0x18.
extern "C" void GameState_ProcessPendingOperationIfPresent(void *object) {
    if (*(int *)((char *)object + 0x38))
        func_ov017_021d4e38(object);
}
