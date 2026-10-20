#include "System/Interrupts.h"
#include "System/DMA.h"
#include "System/InterruptResponse.h"
#include "System/BiosData.h"
#include "System/DTCM.h"
#include <globaldefs.h>
#include <asmhacks.h>

#pragma optimize_for_size off

inline DMACompletionCallback& CallbackByIndex(int n, int base = 0)
{
    return *(DMACompletionCallback*)((unsigned int)&GetInterruptHandler_UnknownRoleZeroInitializedStorage[base].callback + n * sizeof(DMAOrTimerResponse));
}

inline unsigned int& ShouldStayEnabledByIndex(int n, int base = 0)
{
    return *(unsigned int*)((unsigned int)&GetInterruptHandler_UnknownRoleZeroInitializedStorage[base].stayEnabledAfter + n * sizeof(DMAOrTimerResponse));
}

inline int& CallbackUserdataByIndex(int n, int base = 0)
{
    return *(int*)((unsigned int)&GetInterruptHandler_UnknownRoleZeroInitializedStorage[base].userdata + n * sizeof(DMAOrTimerResponse));
}

// Start of exposed functions

void WaitForInterrupt(bool onlySubsequent, unsigned int mask)
{
    int priorState = DisableIRQInterrupts();
    if (onlySubsequent)
        DTCM_DATA.interruptsFired &= ~mask;
    SetIRQInterruptState(priorState);
    
    if (!(mask & DTCM_DATA.interruptsFired))
    {
        BlockedContextList* list = &Entry_UnknownRoleProcedureReferenceRecords.block_60;
        unsigned int* pData;
        do {
            pData = &DTCM_DATA.interruptsFired;
            BlockCurrentContext(list);
        } while (!(mask & *pData));
    }
    DECLARE_ASM_NOP();
}

void EmptyInterruptHandler() {}

// This function matches with wrong registers
void OnDMAOrTimerCompletion(int index)
{
    unsigned int irqId = OnDMAOrTimerCompletion_UnknownRoleInitializedBytes[index];
    unsigned int irqMask = 1 << irqId;

    DMACompletionCallback callback = CallbackByIndex(index);
    CallbackByIndex(index) = NULL;

    if (callback != NULL)
        callback(CallbackUserdataByIndex(index));
        
    
    unsigned int stayEnabled = 0;
    
    DTCMData& itcm = DTCM_DATA;
    stayEnabled = ShouldStayEnabledByIndex(index);
    itcm.interruptsFired |= irqMask;
    

    if (!stayEnabled)
    {
        DisableSpecificInterrupts(irqMask);
    }
}

void InitializeInterruptBlockedThreadList()
{
    BlockedContextList& list = GetInterruptDataBlockedContextList();
    list.first = list.last = NULL;
}

// This function matches but with wrong registers
// proc can either be of type void(*)() for regular interrupts,
// or void(*)(int) for DMA / timer response interrupts
void SetInterruptHandler(unsigned int mask, const void* proc)
{
    InterruptHandlerProc* regularTable;
    int dmaTimerIndex;
    DMAOrTimerResponse* specialTable;
    
    int interruptID;
    
    regularTable = Entry_UnknownRoleProcedureReferenceRecords.interruptProcTable;
    specialTable = GetInterruptHandler_UnknownRoleZeroInitializedStorage;
    interruptID = 0;
    do {
        
        if (mask & 1)
        {
            DMAOrTimerResponse* dmaTimerData = NULL;
            // DMA channels
            if (interruptID >= 8 && interruptID <= 11)
            {
                int dmaTimerIndex = interruptID - 8;
                dmaTimerData = &specialTable[dmaTimerIndex];
            }
            // timer overflows
            else if (interruptID >= 3 && interruptID <= 6)
            {
                dmaTimerIndex = interruptID + 1;
                dmaTimerData = &specialTable[dmaTimerIndex];
            }
            else
            {
                regularTable[interruptID] = (InterruptHandlerProc)proc;
            }

            if (dmaTimerData != NULL)
            {
                dmaTimerData->callback = (DMACompletionCallback)proc;
                dmaTimerData->userdata = 0;
                dmaTimerData->stayEnabledAfter = true;
            }
        }
        interruptID++;
        mask >>= 1;
    } while (interruptID < 22);
}

