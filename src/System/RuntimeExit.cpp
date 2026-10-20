#include "System/Mutex.h"
#include "System/RuntimeStream.h"
#include "System/RuntimeState.h"
#pragma optimize_for_size off
#pragma dont_inline on

// Keep the handler fetch before publishing the decremented callback count.
// Original data: arm9/main @ 0x20f2fb8; symbol: data_020f2fb8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 168 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Mutex RuntimeRunRegisteredExitHandlersAndTerminate_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int Runtime_DispatchSignalHandler(int);
extern "C" void RuntimeDestructors_DestroyRegisteredObjects();
extern "C" void Runtime_InvokeConsoleExitHook();
extern "C" void Runtime_RunEarlyExitHandlerAndTerminate(int);
extern "C" void Runtime_RunRegisteredExitHandlersAndTerminate(int);

// Original: arm9/main @ 0x02001578; symbol: func_02001578; size: 0x24.
extern "C" void Runtime_AbortProcess()
{
    Runtime_DispatchSignalHandler(1);
    RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.aborting = 1;
    Runtime_RunEarlyExitHandlerAndTerminate(1);
}
// Original: arm9/main @ 0x0200159C; symbol: func_0200159c; size: 0x4C.
extern "C" void Runtime_RunEarlyExitHandlerAndTerminate(int status)
{
    if (!RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.aborting) {
        RuntimeDestructors_DestroyRegisteredObjects();
        if (RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.earlyHandler) {
            RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.earlyHandler();
            RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.earlyHandler = 0;
        }
    }
    Runtime_RunRegisteredExitHandlersAndTerminate(status);
}
// Original: arm9/main @ 0x020015E8; symbol: func_020015e8; size: 0x128.
extern "C" void Runtime_RunRegisteredExitHandlersAndTerminate(int)
{
    // Preserve the runtime's observed recursive-lock return-value test.
    if (!TryLockMutex(&RuntimeRunRegisteredExitHandlersAndTerminate_UnknownRoleZeroInitializedStorage_Variant2)) {
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage[0] = OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.activeContext->uniqueID;
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[0] = 1;
    } else if (RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage[0] == OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.activeContext->uniqueID) {
        ++RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[0];
    } else {
        LockMutex(&RuntimeRunRegisteredExitHandlersAndTerminate_UnknownRoleZeroInitializedStorage_Variant2);
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage[0] = OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.activeContext->uniqueID;
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[0] = 1;
    }
    if (RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.handlerCount > 0) {
        do {
            int index = RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.handlerCount - 1;
            RuntimeExitHandler handler = RuntimeRunRegisteredExitHandlersAndTerminate_UnknownRoleZeroInitializedStorage[index];
            RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.handlerCount = index;
            handler();
        } while (RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.handlerCount > 0);
    }
    if (--RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[0] == 0)
        UnlockMutex(&RuntimeRunRegisteredExitHandlersAndTerminate_UnknownRoleZeroInitializedStorage_Variant2);
    if (RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.lateHandler) {
        RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.lateHandler();
        RuntimeAbortProcess_UnknownRoleZeroInitializedStorage.lateHandler = 0;
    }
    RuntimeStreamBuffers_FlushStreamOrAllStreams(0);
    Runtime_InvokeConsoleExitHook();
}


