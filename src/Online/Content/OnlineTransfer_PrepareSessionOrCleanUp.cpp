#include <globaldefs.h>
ARM
extern "C" int OnlineTransfer_PrepareSessionResources(void);
extern "C" void OnlineTransfer_CleanUpSession(void *);
// Original: arm9/ov031 @ 0x022436C0; symbol: func_ov031_022436c0; size: 0x20.
extern "C" void OnlineTransfer_PrepareSessionOrCleanUp(void *argument) {
    if (OnlineTransfer_PrepareSessionResources() < 0)
        OnlineTransfer_CleanUpSession(argument);
}
