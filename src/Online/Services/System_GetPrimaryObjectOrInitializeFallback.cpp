#include <globaldefs.h>
ARM
extern "C" void *WirelessConnection_CheckDisconnectError(void);
extern "C" void HashEntropyAndDispatchCompletedCallback(void);
// Original: arm9/ov031 @ 0x0221188C; symbol: func_ov031_0221188c; size: 0x1C.
extern "C" void *System_GetPrimaryObjectOrInitializeFallback(void) {
    void *object = WirelessConnection_CheckDisconnectError();
    if (!object)
        HashEntropyAndDispatchCompletedCallback();
    return object;
}
