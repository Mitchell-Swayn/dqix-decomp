#pragma dont_inline on

/* Priority-ordered waiting/global thread lists and mutex-list removal.
 * Only observed fields are modeled; opaque scheduler/register prefixes do
 * not claim reconstruction or ownership of their storage. */
typedef struct ProcessorContext ProcessorContext;
typedef struct Mutex Mutex;
typedef struct { ProcessorContext *first,*last; } BlockedContextList;
typedef struct { Mutex *pFirst,*pLast; } MutexList;
struct ProcessorContext { char registers[0x48]; int state; ProcessorContext *pNext; unsigned int uniqueID,priority,unknown58; BlockedContextList *container; ProcessorContext *pPrevBlocked,*pNextBlocked; };
struct Mutex { BlockedContextList waiters; ProcessorContext *owner; int count; Mutex *pNext_,*pPrev_; };
typedef struct { char prefix[0x2c]; ProcessorContext *firstContext; } ThreadGlobals;
extern ThreadGlobals ARM7_ThreadGlobals;
void ARM7_InsertBlockedThread(BlockedContextList *queue, ProcessorContext* insertion)
{
    ProcessorContext* elementAfter = queue->first;
    while (elementAfter != 0 && elementAfter->priority <= insertion->priority)
    {
        if (elementAfter == insertion)
            return;
        elementAfter = elementAfter->pNextBlocked;
    }

    if (elementAfter == 0)
    {
        // Insert at end
        ProcessorContext* elementBefore = queue->last;
        if (elementBefore == 0)
            queue->first = insertion;
        else
            elementBefore->pNextBlocked = insertion;
        insertion->pPrevBlocked = elementBefore;
        insertion->pNextBlocked = 0;
        queue->last = insertion;
    }
    else
    {
        ProcessorContext* elementBefore = elementAfter->pPrevBlocked;
        if (elementBefore == 0)
            queue->first = insertion;
        else
            elementBefore->pNextBlocked = insertion;
        insertion->pPrevBlocked = elementBefore;
        insertion->pNextBlocked = elementAfter;
        elementAfter->pPrevBlocked = insertion;
    }
}

ProcessorContext* ARM7_RemoveBlockedThread(BlockedContextList *queue, ProcessorContext* context)
{
    ProcessorContext* searchNode = queue->first;
    ProcessorContext* nodeAfter;
    ProcessorContext* nodeBefore;

    while (searchNode != 0)
    {
        nodeAfter = searchNode->pNextBlocked;
        if (searchNode == context)
        {
            nodeBefore = searchNode->pPrevBlocked;
            if (queue->first == searchNode)
                queue->first = nodeAfter;
            else
                nodeBefore->pNextBlocked = nodeAfter;
            if (queue->last == searchNode)
                queue->last = nodeBefore;
            else
                nodeAfter->pPrevBlocked = nodeBefore;
            break;
        }
        searchNode = nodeAfter;
    }
    return searchNode;
}

Mutex* ARM7_PopFrontMutexFromList(MutexList* list)
{
    Mutex* front = list->pFirst;
    if (front != 0)
    {
        Mutex* next = front->pNext_;
        list->pFirst = next;
        if (next != 0)  
            next->pPrev_ = 0;
        else
            list->pLast = 0;
    }
    return front;
}

ProcessorContext* ARM7_InsertThreadGlobal(ProcessorContext *context)
{
    ProcessorContext* loopEntry = ARM7_ThreadGlobals.firstContext;
    ProcessorContext* nodeBefore = 0;

    while (loopEntry != 0 && loopEntry->priority < context->priority)
    {
        nodeBefore = loopEntry;
        loopEntry = loopEntry->pNext;
    }

    if (nodeBefore == 0)
    {
        context->pNext = ARM7_ThreadGlobals.firstContext;
        ARM7_ThreadGlobals.firstContext = context;
    }
    else
    {
        context->pNext = nodeBefore->pNext;
        nodeBefore->pNext = context;
    }
    return context;
}

void ARM7_RemoveThreadGlobal(ProcessorContext *context)
{
    ProcessorContext* loopEntry = ARM7_ThreadGlobals.firstContext;
    ProcessorContext* nodeBefore = 0;

    while (loopEntry != 0 && loopEntry != context)
    {
        nodeBefore = loopEntry;
        loopEntry = loopEntry->pNext;
    }

    if (nodeBefore == 0)
        ARM7_ThreadGlobals.firstContext = context->pNext;
    else
        nodeBefore->pNext = context->pNext;
}

