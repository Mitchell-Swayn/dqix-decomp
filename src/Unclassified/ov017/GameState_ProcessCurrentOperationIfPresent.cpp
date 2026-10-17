#include <globaldefs.h>
ARM
extern "C" void func_ov003_0217480c(void);
extern "C" unsigned int data_ov017_021d840c;
// Original: arm9/ov017 @ 0x021B2F0C; symbol: func_ov017_021b2f0c; size: 0x20.
extern "C" void GameState_ProcessCurrentOperationIfPresent(void) {
    if (data_ov017_021d840c == 0)
        return;
    func_ov003_0217480c();
}
