#include "Filesystem/CardReadManager.h"
#include "Filesystem/FSInnerDefs.h"
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

extern "C" {
void OSi_ReferSymbol(unsigned int);
void DisableInterruptsAndHaltForever();
void CARDi_IdentifyBackupCore(int);
int CardReadManager_SendSharedCommandWithRetries(CardReadManager*, unsigned int, unsigned int);
}

// Original: arm9/main @ 0x020D06FC; symbol: func_020d06fc; size: 0x138.
extern "C" ARM bool CardReadManager_ExecuteModeCommandSynchronously(int mode)
{
    CardReadManager* manager = &TryReadViaDMA_UnknownRoleZeroInitializedStorage;
    OSi_ReferSymbol(0x02000bc4);
    if (mode == 0)
        DisableInterruptsAndHaltForever();
    VerifyCardReadManagerInitialized();
    int oldState = DisableIRQInterrupts();
    int flags = (int)manager->flags;
    if ((flags & 4) != 0)
    {
        do {
            BlockCurrentContext(&manager->ongoingReadBlock);
        } while ((manager->flags & 4) != 0);
    }
    manager->flags |= 4;
    manager->onComplete = 0;
    manager->handle = 0;
    SetIRQInterruptState(oldState);
    CARDi_IdentifyBackupCore(mode);
    TryReadViaDMA_UnknownRoleZeroInitializedStorage.currentTaskExecutionContext = OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.activeContext;
    CardReadManager_SendSharedCommandWithRetries(manager, 2, 1);
    Arm7CardReadData* volatile* sharedSlot = &manager->pSharedData;
    ((unsigned int*)*sharedSlot)[3] = 0;
    ((unsigned int*)*sharedSlot)[4] = (unsigned int)manager->unknown;
    ((unsigned int*)*sharedSlot)[5] = 1;
    CardReadManager_SendSharedCommandWithRetries(manager, 6, 1);
    NitroHandle* callbackArg;
    CardReadManager::CompletionCallback callback = manager->onComplete;
    callbackArg = manager->handle;
    oldState = DisableIRQInterrupts();
    manager->flags &= ~0x4c;
    UnblockContexts(&manager->ongoingReadBlock);
    if ((manager->flags & 0x10) != 0)
        MarkContextReadyAndSwitch(&manager->cartridgeReadContext);
    SetIRQInterruptState(oldState);
    if (callback != 0)
        callback(callbackArg);
    return manager->pSharedData->unknown_0 == 0;
}
