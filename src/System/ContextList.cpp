#include "System/ProcessorContext.h"
#include "System/Mutex.h"
#include "System/Interrupts.h"
#include <globaldefs.h>
#include <asmhacks.h>

extern "C"
{
    void func_020c7c30();

    void func_020c7c08(PFNSwitchContextProc);
    void func_020c75b4(ProcessorContext*, const void* proc, void* maybeUserdata, void* stackBottom, unsigned stackSize, int prio);
}

// Original: arm9/main @ 0x020C71A4; symbol: _Z23GenerateUniqueContextIDv; size: 0x18.
int GenerateUniqueContextID()
{
    return ++(OSInitThread_UnknownRoleZeroInitializedStorage.contextUniqueIDCounter);
}

#pragma optimize_for_size off

// Original: arm9/main @ 0x020C71BC; symbol: _ZN18BlockedContextList6InsertEP16ProcessorContext; size: 0x78.
void BlockedContextList::Insert(ProcessorContext* insertion)
{
    ProcessorContext* elementAfter = this->first;
    while (elementAfter != NULL && elementAfter->priority <= insertion->priority)
    {
        if (elementAfter == insertion)
            return;
        elementAfter = elementAfter->pNextBlocked;
    }

    if (elementAfter == NULL)
    {
        // Insert at end
        ProcessorContext* elementBefore = this->last;
        if (elementBefore == NULL)
            this->first = insertion;
        else
            elementBefore->pNextBlocked = insertion;
        insertion->pPrevBlocked = elementBefore;
        insertion->pNextBlocked = NULL;
        this->last = insertion;
    }
    else
    {
        ProcessorContext* elementBefore = elementAfter->pPrevBlocked;
        if (elementBefore == NULL)
            this->first = insertion;
        else
            elementBefore->pNextBlocked = insertion;
        insertion->pPrevBlocked = elementBefore;
        insertion->pNextBlocked = elementAfter;
        elementAfter->pPrevBlocked = insertion;
    }
}

// Original: arm9/main @ 0x020C7234; symbol: _ZN18BlockedContextList8PopFrontEv; size: 0x34.
ProcessorContext* BlockedContextList::PopFront()
{
    ProcessorContext* front = this->first;
    if (front != NULL)
    {
        ProcessorContext* newFront = front->pNextBlocked;
        this->first = newFront;
        if (newFront != NULL)
            newFront->pPrevBlocked = NULL;
        else
        {
            this->last = NULL;
            // Slightly strange that this only happens if we empty the list, but
            // the function calling this also clears this entry manually in all
            // popped contexts
            front->containerBlockedQueue = NULL;
        }
    }
    return front;
}

// Original: arm9/main @ 0x020C7268; symbol: _ZN18BlockedContextList6RemoveEP16ProcessorContext; size: 0x54.
ProcessorContext* BlockedContextList::Remove(ProcessorContext* context)
{
    ProcessorContext* searchNode = this->first;
    ProcessorContext* nodeAfter;
    ProcessorContext* nodeBefore;

    if (searchNode != NULL)
    {
        do
        {
            nodeAfter = searchNode->pNextBlocked;
            if (searchNode != context)
                continue;

            nodeBefore = searchNode->pPrevBlocked;
            
            if (this->first == searchNode)
                this->first = nodeAfter;
            else
                nodeBefore->pNextBlocked = nodeAfter;

            if (this->last == searchNode)
                this->last = nodeBefore;
            else
                nodeAfter->pPrevBlocked = nodeBefore;
            
            break;
        } while ((searchNode = nodeAfter) != NULL);
    }
    return searchNode;
}

// Original: arm9/main @ 0x020C72BC; symbol: _Z21PopFrontMutexFromListP9MutexList; size: 0x30.
Mutex* PopFrontMutexFromList(MutexList* list)
{
    Mutex* front = list->pFirst;
    if (front != NULL)
    {
        Mutex* next = front->pNext_;
        list->pFirst = next;
        if (next != NULL)  
            next->pPrev_ = NULL;
        else
            list->pLast = NULL;
    }
    return front;
}

// Original: arm9/main @ 0x020C72EC; symbol: _Z27InsertContextIntoGlobalListP16ProcessorContext; size: 0x60.
ProcessorContext* InsertContextIntoGlobalList(ProcessorContext *context)
{
    ProcessorContext* loopEntry = OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext;
    ProcessorContext* nodeBefore = NULL;

    while (loopEntry != NULL && loopEntry->priority < context->priority)
    {
        nodeBefore = loopEntry;
        loopEntry = loopEntry->pNext;
    }

    if (nodeBefore == NULL)
    {
        context->pNext = OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext;
        OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext = context;
    }
    else
    {
        context->pNext = nodeBefore->pNext;
        nodeBefore->pNext = context;
    }
    return context;
}

// Original: arm9/main @ 0x020C734C; symbol: _Z27RemoveContextFromGlobalListP16ProcessorContext; size: 0x48.
void RemoveContextFromGlobalList(ProcessorContext *context)
{
    ProcessorContext* loopEntry = OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext;
    ProcessorContext* nodeBefore = NULL;

    while (loopEntry != NULL && loopEntry != context)
    {
        nodeBefore = loopEntry;
        loopEntry = loopEntry->pNext;
    }

    if (nodeBefore == NULL)
        OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.firstContext = context->pNext;
    else
        nodeBefore->pNext = context->pNext;
}

// Original: arm9/main @ 0x020C7394; symbol: _Z13SwitchContextv; size: 0xC8.
void SwitchContext()
{
    if (OSInitThread_UnknownRoleZeroInitializedStorage.contextSwitchLock != 0)
        return;

    Struct_02111304* contextData = &OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24;

    // 0x12 = interrupt handling mode
    if (OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.unknown_2 != 0 || GetProcessorMode() == 0x12)
    {
        contextData->unknown_0 = true;
        return;
    }

    ProcessorContext* outgoing = *(OSInitThread_UnknownRoleZeroInitializedStorage.ppActiveContext);
    ProcessorContext* incoming = GetFirstReadyContext();

    if (outgoing == incoming || incoming == NULL)
        return;

    if (outgoing->blockState != CONTEXT_STATE_INVALID)
    {
        if (OS_SaveContext(outgoing) != 0)
            return;
    }

    if (OSInitThread_UnknownRoleZeroInitializedStorage.switchContextProcA != NULL)
        OSInitThread_UnknownRoleZeroInitializedStorage.switchContextProcA(outgoing, incoming);

    if (contextData->switchContextProcB != NULL)
        contextData->switchContextProcB(outgoing, incoming);

    OSInitThread_UnknownRoleZeroInitializedStorage.substruct_24.activeContext = incoming;
    OS_LoadContext(incoming);
}