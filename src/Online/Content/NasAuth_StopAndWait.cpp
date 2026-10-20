#include <globaldefs.h>
ARM
extern "C" void System_StopSharedWorkerAndAwaitContext(void);
// Original: arm9/ov031 @ 0x02212784; symbol: func_ov031_02212784; size: 0xC.
extern "C" void NasAuth_StopAndWait(void) {
    System_StopSharedWorkerAndAwaitContext();
}
