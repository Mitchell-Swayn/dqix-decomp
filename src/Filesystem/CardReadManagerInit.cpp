#include "Filesystem/CardReadManager.h"
#include "System/BiosData.h"
#include "System/Interrupts.h"
#include "System/Cache.h"
#include "System/IPC.h"
#include "System/Memory.h"
#include "Filesystem/FSInnerDefs.h"
#include <asmhacks.h>

#pragma optimize_for_size off

#if defined(jpn)
#define MIi_CpuClearFast func_020cbf24
#define DisableInterruptsAndHaltForever func_020cb6ac

#define IsCardReadManagerInitialized_UnknownRoleZeroInitializedStorage data_02111500
#endif

extern "C"
{
    // memset but tries to do 32 bytes at a time
    void MIi_CpuClearFast(int value, void* dst, unsigned len);

    // abort() or fatal error or similar
    void DisableInterruptsAndHaltForever();
}
// is card read manager initialized
// Original data: arm9/main @ 0x2111860; symbol: data_02111860.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int IsCardReadManagerInitialized_UnknownRoleZeroInitializedStorage;

void MarkCardReadManagerInitialized(int to);

// Original: arm9/main @ 0x020CFCBC; symbol: _Z21SendTaskToReadContextPFvP15CardReadManagerE; size: 0x3C.
void SendTaskToReadContext(CardReadManager::ReadProc task)
{
    CardReadManager* readManager = (CardReadManager*)&TryReadViaDMA_UnknownRoleZeroInitializedStorage;
    ChangeContextPriority(&readManager->cartridgeReadContext, TryReadViaDMA_UnknownRoleZeroInitializedStorage.contextPriority_108);
    readManager->currentTaskExecutionContext = &readManager->cartridgeReadContext;
    readManager->cartridgeReadProc = task;
    readManager->flags |= (1 << READ_MANAGER_FLAG_CONTEXT_HAS_TASK_PENDING);
    MarkContextReadyAndSwitch(&readManager->cartridgeReadContext);
}

// Original: arm9/main @ 0x020CFCF8; symbol: _Z19LockCardReadManagerti; size: 0x84.
void LockCardReadManager(unsigned short ownerID, int taskType)
{
    CardReadManager* manager = &TryReadViaDMA_UnknownRoleZeroInitializedStorage;
    volatile CardReadManager* volMan = manager;
    // here we access owner & multiplicity via volatile, but 
    // owner & taskType works too.
    int priorState = DisableIRQInterrupts();
    if (volMan->lock.owner == ownerID)
    {
        if (manager->lock.taskType != taskType)
            DisableInterruptsAndHaltForever();
    }
    else
    {
        while (volMan->lock.owner != -3)
            BlockCurrentContext(&manager->lock.waitingContexts);
        volMan->lock.owner = ownerID;
        manager->lock.taskType = taskType;
    }
    
    volMan->lock.multiplicity++;
    manager->pSharedData->unknown_0 = 0;
    SetIRQInterruptState(priorState);
}

// Original: arm9/main @ 0x020CFD7C; symbol: _Z21UnlockCardReadManagerti; size: 0x8C.
void UnlockCardReadManager(unsigned short ownerID, int taskType)
{
    CardReadManager* manager = &TryReadViaDMA_UnknownRoleZeroInitializedStorage;
    volatile CardReadManager* volMan = manager;
    int priorState = DisableIRQInterrupts();
    if (volMan->lock.owner != ownerID || volMan->lock.multiplicity == 0)
    {
        DisableInterruptsAndHaltForever();
    }
    else
    {
        if (manager->lock.taskType != taskType)
            DisableInterruptsAndHaltForever();
        int multiplicity = volMan->lock.multiplicity;
        multiplicity--;
        volMan->lock.multiplicity = multiplicity;
        if (multiplicity == 0)
        {
            volMan->lock.owner = -3;
            manager->lock.taskType = 0;
            UnblockContexts(&manager->lock.waitingContexts);
        }
    }
    
    manager->pSharedData->unknown_0 = 0;
    SetIRQInterruptState(priorState);
}

// Original: arm9/main @ 0x020CFE08; symbol: _Z25InitializeCardReadManagerv; size: 0x110.
void InitializeCardReadManager()
{
    CardReadManager* manager = &TryReadViaDMA_UnknownRoleZeroInitializedStorage;
    volatile CardReadManager* volatileManager = manager;

    // two of these need to be volatile and definitely owner
    volatileManager->lock.owner = -3;
    volatileManager->lock.multiplicity = 0;
    manager->lock.taskType = 0;
    manager->pSharedData = &InitializeCardReadManager_UnknownRoleZeroInitializedStorage;
    
    MIi_CpuClearFast(0, &InitializeCardReadManager_UnknownRoleZeroInitializedStorage, sizeof(Arm7CardReadData));
    CleanInvalidateCacheRange(&InitializeCardReadManager_UnknownRoleZeroInitializedStorage, sizeof(Arm7CardReadData));
    manager->instructionCacheCleanThreshold = 0xffffffff;
    manager->dataCacheCleanThreshold = 0xffffffff;
    
    if (!IsDownloadPlay())
        MI_CpuCopy8((void*)BIOS_ADDR_CARTRIDGE_HEADER, (void*)0x027ffa80, 0x160);
    
    manager->contextPriority_108 = 4;
    manager->lock.waitingContexts.last = 0;
    manager->lock.waitingContexts.first = 0;
    manager->ongoingReadBlock.last = 0;
    manager->ongoingReadBlock.first = 0;

    PopulateProcessorContext(&manager->cartridgeReadContext, (unsigned int)&CartridgeReadContextLoop, 0, (unsigned int)(&TryReadViaDMA_UnknownRoleZeroInitializedStorage + 1), 0x400, manager->contextPriority_108);
    MarkContextReadyAndSwitch(&manager->cartridgeReadContext);
    SetArm9IPCCommandHandler(11, &IPCCommand11Proc);

    if (IsDownloadPlay())
    {
        DECLARE_ASM_NOP();
        return;
    }
    MarkCardReadManagerInitialized(true);    
}

// Original: arm9/main @ 0x020CFF18; symbol: _Z28IsCardReadManagerInitializedv; size: 0x10.
int IsCardReadManagerInitialized()
{
    return IsCardReadManagerInitialized_UnknownRoleZeroInitializedStorage;
}

// Original: arm9/main @ 0x020CFF28; symbol: _Z32VerifyCardReadManagerInitializedv; size: 0x18.
void VerifyCardReadManagerInitialized()
{
    if (!IsCardReadManagerInitialized())
        DisableInterruptsAndHaltForever();
}

// Original: arm9/main @ 0x020CFF40; symbol: _Z30MarkCardReadManagerInitializedi; size: 0x10.
void MarkCardReadManagerInitialized(int to)
{
    IsCardReadManagerInitialized_UnknownRoleZeroInitializedStorage = to;
}

// Original: arm9/main @ 0x020CFF50; symbol: _Z24AwaitCardReadManagerIdlev; size: 0x4C.
bool AwaitCardReadManagerIdle()
{
    CardReadManager* manager = &TryReadViaDMA_UnknownRoleZeroInitializedStorage;
    int priorState = DisableIRQInterrupts();
    while (manager->flags & (1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS))
        BlockCurrentContext(&manager->ongoingReadBlock);
    SetIRQInterruptState(priorState);
    return manager->pSharedData->unknown_0 == 0;
}

// Original: arm9/main @ 0x020CFF9C; symbol: _Z21IsCardReadManagerIdlev; size: 0x1C.
bool IsCardReadManagerIdle()
{
    CardReadManager* manager = &TryReadViaDMA_UnknownRoleZeroInitializedStorage;
    return !(manager->flags & (1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS));
}

// Original: arm9/main @ 0x020CFFB8; symbol: _Z30GetCardReadManagerSharedStatusv; size: 0x14.
int GetCardReadManagerSharedStatus()
{
    CardReadManager* manager = &TryReadViaDMA_UnknownRoleZeroInitializedStorage;
    return manager->pSharedData->unknown_0;
}