#include "System/Mutex.h"
#include "System/RuntimeStream.h"
#include "System/RuntimeState.h"
#pragma optimize_for_size off
#pragma dont_inline on

// Keep the handler fetch before publishing the decremented callback count.
extern Mutex data_020f2fb8;
extern "C" int Runtime_DispatchSignalHandler(int);
extern "C" void RuntimeDestructors_DestroyRegisteredObjects();
extern "C" void Runtime_InvokeConsoleExitHook();
extern "C" void Runtime_RunEarlyExitHandlerAndTerminate(int);
extern "C" void Runtime_RunRegisteredExitHandlersAndTerminate(int);

// Original: arm9/main @ 0x02001578; symbol: func_02001578; size: 0x24.
extern "C" void Runtime_AbortProcess()
{
    Runtime_DispatchSignalHandler(1);
    data_020f2e60.aborting = 1;
    Runtime_RunEarlyExitHandlerAndTerminate(1);
}
// Original: arm9/main @ 0x0200159C; symbol: func_0200159c; size: 0x4C.
extern "C" void Runtime_RunEarlyExitHandlerAndTerminate(int status)
{
    if (!data_020f2e60.aborting) {
        RuntimeDestructors_DestroyRegisteredObjects();
        if (data_020f2e60.earlyHandler) {
            data_020f2e60.earlyHandler();
            data_020f2e60.earlyHandler = 0;
        }
    }
    Runtime_RunRegisteredExitHandlersAndTerminate(status);
}
// Original: arm9/main @ 0x020015E8; symbol: func_020015e8; size: 0x128.
extern "C" void Runtime_RunRegisteredExitHandlersAndTerminate(int)
{
    // Preserve the runtime's observed recursive-lock return-value test.
    if (!TryLockMutex(&data_020f2fb8)) {
        data_020f2f70[0] = data_02111304.activeContext->uniqueID;
        data_020f2f94[0] = 1;
    } else if (data_020f2f70[0] == data_02111304.activeContext->uniqueID) {
        ++data_020f2f94[0];
    } else {
        LockMutex(&data_020f2fb8);
        data_020f2f70[0] = data_02111304.activeContext->uniqueID;
        data_020f2f94[0] = 1;
    }
    if (data_020f2e60.handlerCount > 0) {
        do {
            int index = data_020f2e60.handlerCount - 1;
            RuntimeExitHandler handler = data_020f2e70[index];
            data_020f2e60.handlerCount = index;
            handler();
        } while (data_020f2e60.handlerCount > 0);
    }
    if (--data_020f2f94[0] == 0)
        UnlockMutex(&data_020f2fb8);
    if (data_020f2e60.lateHandler) {
        data_020f2e60.lateHandler();
        data_020f2e60.lateHandler = 0;
    }
    RuntimeStreamBuffers_FlushStreamOrAllStreams(0);
    Runtime_InvokeConsoleExitHook();
}


