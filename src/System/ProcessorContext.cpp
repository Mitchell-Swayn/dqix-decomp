#include "System/ProcessorContext.h"
#include "System/Mutex.h"
#include "System/Timing.h"
#include "System/Interrupts.h"
#include <globaldefs.h>
#include <asmhacks.h>

#pragma dont_inline on
#pragma optimize_for_size off

#if defined(jpn)
#define func_020c9bf0 func_020cb6bc
#define func_020c9be0 func_020cb6ac
#define func_020ca3ec func_020cbeb8
#endif

extern "C"
{
    // wait for an interrupt
    void func_020c9bf0();

    // something like abort()
    void func_020c9be0();

    // memset with silly signature and assuming alignment
    void func_020ca3ec(int value, void* dst, unsigned len);
}

void CycleCurrentPriorityContexts()
{
    ProcessorContext* contextBeforeActive = NULL;
    ProcessorContext* lastEqualPriorityContext = NULL;
    int numEqualPriorityContexts = 0;

    int priorState;

    ProcessorContext* active = data_021112e0.substruct_24.activeContext;
    priorState = DisableIRQInterrupts();
    

    ProcessorContext* loopPrevContext = NULL;    
    ProcessorContext* loopContext = data_021112e0.substruct_24.firstContext;
    if (data_021112e0.substruct_24.firstContext != NULL)
    {
        unsigned int targetPriority = active->priority;
        do {
            if (loopContext == active)
                contextBeforeActive = loopPrevContext;

            if (targetPriority == loopContext->priority)
            {
                lastEqualPriorityContext = loopContext;
                numEqualPriorityContexts++;
            }

            loopPrevContext = loopContext;
            loopContext = loopContext->pNext;
        } while (loopContext != NULL);
    }

    if (numEqualPriorityContexts <= 1 || lastEqualPriorityContext == active)
    {
        SetIRQInterruptState(priorState);
        return;
    }
    
    if (contextBeforeActive != NULL)
    {
        contextBeforeActive->pNext = active->pNext;
    }
    else
    {
        DECLARE_ASM_NOP();
        data_021112e0.substruct_24.firstContext = active->pNext;
    }

    active->pNext = lastEqualPriorityContext->pNext;
    lastEqualPriorityContext->pNext = active;
    SwitchContext();
    SetIRQInterruptState(priorState);
    return;
}

void MarkContextStackTopUnknownSubspace(ProcessorContext *context, unsigned int size)
{
    context->stackUnknownTopSubspaceSize = size;
    if (size != 0)
    {
        *(int*)(context->stackTop + size) = STACK_UNKNOWN_SECTION_MAGIC;
    }
}

bool ChangeContextPriority(ProcessorContext* context, unsigned int newPriority)
{
    ProcessorContext* loopContext = data_021112e0.substruct_24.firstContext;
    ProcessorContext* prevContext = NULL;
    int priorState = DisableIRQInterrupts();

    for (; loopContext != NULL && loopContext != context; loopContext = loopContext->pNext)
    {
        prevContext = loopContext;
    }

    if (loopContext == NULL || loopContext == &data_021112e0.contextA)
    {
        SetIRQInterruptState(priorState);
        return false;
    }

    if (loopContext->priority != newPriority)
    {
        // Remove context from the list
        if (prevContext != NULL)
            prevContext->pNext = context->pNext;
        else
        {
            DECLARE_ASM_NOP();
            data_021112e0.substruct_24.firstContext = context->pNext;
        }
        
        context->priority = newPriority;
        InsertContextIntoGlobalList(context);
        SwitchContext();
    }
    SetIRQInterruptState(priorState);
    return true;
}

void SleepCurrentContext(unsigned int milliseconds)
{
    Alarm timing;
    ZeroInitializeAlarm(&timing);
    ProcessorContext* context = *data_021112e0.ppActiveContext;

    int priorState = DisableIRQInterrupts();

    uint64_t numTicks = (uint64_t)milliseconds * TIMER_TICKS_PER_MILLISECOND >> 6;
    context->sleepAlarm = &timing;
    SetTimeout(&timing, numTicks, &SleepCompletionProc, &context);

    if (context != NULL)
    {
        do {
            BlockCurrentContext(NULL);
        } while (context != NULL);
    }

    SetIRQInterruptState(priorState);
}

unsigned int AddContextSwitchLock()
{
    int priorState = DisableIRQInterrupts();

    unsigned int oldCount;
    if (data_021112e0.contextSwitchLock < (unsigned int)-1)
    {
        oldCount = data_021112e0.contextSwitchLock;
        data_021112e0.contextSwitchLock++;
    }

    SetIRQInterruptState(priorState);
    return oldCount;
}

unsigned int RemoveContextSwitchLock()
{
    int priorState = DisableIRQInterrupts();

    unsigned int oldCount = 0;
    if (data_021112e0.contextSwitchLock > 0)
    {
        oldCount = data_021112e0.contextSwitchLock;
        data_021112e0.contextSwitchLock--;
    }

    SetIRQInterruptState(priorState);
    return oldCount;
}

void SetContextEndProc(ProcessorContext* context, ProcessorContext::ExitRoutine proc)
{
    context->exitProc = proc;
}

void InitializeContextRegisters(ProcessorContext* context, unsigned int startAddress, unsigned int stackBottom)
{
    unsigned int resumeAddress = startAddress + 4;
    context->resumeAddress = resumeAddress;
    context->supervisorStackPointer = stackBottom;
    stackBottom -= 0x40;
    
    __asm("tst stackBottom, 4");
    __asm("bne adjustStackPtr");
    __asm("b skipAdjustStackPtr");


__asm("adjustStackPtr:");
    stackBottom -= 4;
__asm("skipAdjustStackPtr:");
    context->userModeRegisters[13] = stackBottom;

    unsigned int status;
    __asm("ands status, resumeAddress, 1");
    __asm("bne thumb_mode");
    __asm("b skip_thumb_mode_assignment");
__asm("thumb_mode:");
    status = 0x1f | (1 << 5);
__asm("skip_thumb_mode_assignment:");
    __asm("beq arm_mode");
    __asm("b skip_arm_mode_assignment");
__asm("arm_mode:");
    status = 0x1f;
__asm("skip_arm_mode_assignment:");


    context->programStatusRegister = status;
    context->userModeRegisters[0] = 0;
    context->userModeRegisters[1] = 0;
    context->userModeRegisters[2] = 0;
    context->userModeRegisters[3] = 0;
    context->userModeRegisters[4] = 0;
    context->userModeRegisters[5] = 0;
    context->userModeRegisters[6] = 0;
    context->userModeRegisters[7] = 0;
    context->userModeRegisters[8] = 0;
    context->userModeRegisters[9] = 0;
    context->userModeRegisters[10] = 0;
    context->userModeRegisters[11] = 0;
    context->userModeRegisters[12] = 0;
    context->userModeRegisters[14] = 0;
}