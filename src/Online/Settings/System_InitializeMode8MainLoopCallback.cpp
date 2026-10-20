#include <globaldefs.h>
ARM
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void System_InstallMode0x15CallbackWhenScreen1ContextByte9IsZero(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x0222D094; symbol: func_ov031_0222d094; size: 0x1C.
extern "C" void System_InitializeMode8MainLoopCallback(void) {
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(System_InstallMode0x15CallbackWhenScreen1ContextByte9IsZero);
}
