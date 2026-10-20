#include "System/Mutex.h"
#include "System/RuntimeState.h"
#pragma optimize_for_size off

// Original data: arm9/main @ 0x20f3060; symbol: data_020f3060.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Mutex RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void Runtime_RunEarlyExitHandlerAndTerminate(int);

// Original: arm9/main @ 0x02003DDC; symbol: func_02003ddc; size: 0x130.
extern "C" int Runtime_DispatchSignalHandler(int signal)
{
    if (signal < 1 || signal > 7)
        return -1;
    // Preserve the original return-value test and recursive bookkeeping.
    if (!TryLockMutex(&RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant3)) {
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage[7] = OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.activeContext->uniqueID;
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[7] = 1;
    } else if (RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage[7] == OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.activeContext->uniqueID) {
        ++RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[7];
    } else {
        LockMutex(&RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant3);
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage[7] = OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.activeContext->uniqueID;
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[7] = 1;
    }
    RuntimeSignalHandler handler = RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant4[signal - 1];
    if (handler != (RuntimeSignalHandler)1)
        RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant4[signal - 1] = 0;
    if (--RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[7] == 0)
        UnlockMutex(&RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant3);
    if (handler == (RuntimeSignalHandler)1 || (handler == 0 && signal == 1))
        return 0;
    if (handler == 0)
        Runtime_RunEarlyExitHandlerAndTerminate(0);
    handler(signal);
    return 0;
}

