#include <globaldefs.h>
ARM
extern "C" int System_QueueTimedCallbackForSharedRecord(unsigned short value);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InstallCallbackIfContextByteClear(void);
// Original: arm9/ov031 @ 0x0222DE08; symbol: System_QueueTimedCallbackAndSetContextHandler; size: 0x1C.
// Queues selector 8 and installs the context handler as the main-loop callback.
extern "C" void System_QueueTimedCallbackAndSetContextHandler(void) {
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(System_InstallCallbackIfContextByteClear);
}
