#include "Filesystem/CardReadManager.h"
#include "Filesystem/FSInnerDefs.h"
#include "System/Interrupts.h"
#include "System/GamecardBusOwnership.h"

#pragma optimize_for_size off

// Original: arm9/main @ 0x020CFFCC; symbol: _Z22SetReadContextPriorityj; size: 0x3C.
unsigned int SetReadContextPriority(unsigned int priority)
{
    CardReadManager* manager = (CardReadManager*)&data_021118e0;
    int priorState = DisableIRQInterrupts();
    unsigned int oldPrio = manager->contextPriority_108;
    manager->contextPriority_108 = priority;
    ChangeContextPriority(&manager->cartridgeReadContext, priority);
    SetIRQInterruptState(priorState);
    return oldPrio;
}

// Original: arm9/main @ 0x020D0008; symbol: _Z40NitroVM_Command_AcquireCardReadResourcest; size: 0x1C.
void NitroVM_Command_AcquireCardReadResources(unsigned short ownerID)
{
    LockCardReadManager(ownerID, 1);
    AcquireNDSBus(ownerID);
}

// Original: arm9/main @ 0x020D0024; symbol: _Z40NitroVM_Command_ReleaseCardReadResourcest; size: 0x1C.
void NitroVM_Command_ReleaseCardReadResources(unsigned short ownerID)
{
    ReleaseNDSBus(ownerID);
    UnlockCardReadManager(ownerID, 1);
}