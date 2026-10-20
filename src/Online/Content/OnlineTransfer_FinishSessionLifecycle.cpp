#include <globaldefs.h>
ARM
extern "C" void OnlineTransfer_CleanUpSession();

// Original: arm9/ov031 @ 0x02243708; symbol: func_ov031_02243708; size: 0xC.
extern "C" void OnlineTransfer_FinishSessionLifecycle(void) {
    OnlineTransfer_CleanUpSession();
}
