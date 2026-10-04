#pragma dont_inline on

/* Recursive mutexes retain a list in their owning thread. Thread structure
 * prefixes below are intentionally partial; only observed mutex fields are
 * modeled, and the external scheduler state is not newly owned data. */
typedef struct ProcessorContext ProcessorContext;
typedef struct Mutex Mutex;
typedef struct { ProcessorContext *first,*last; } ThreadQueue;
typedef struct { Mutex *pFirst,*pLast; } MutexList;
struct ProcessorContext { char unknown[0x68]; Mutex *blockingMutex; MutexList lockedMutexes; };
struct Mutex { ThreadQueue waitingContexts_; ProcessorContext *ownedContext_; int ownerRefcount_; Mutex *pNext_,*pPrev_; };
typedef struct { unsigned int unknown; ProcessorContext *activeContext; } ThreadSystem;
extern ThreadSystem ARM7_ThreadSystem;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_BlockCurrentThread(ThreadQueue*);
extern void ARM7_UnblockThreads(ThreadQueue*);
extern Mutex* ARM7_PopFrontMutexFromList(MutexList*);
void ARM7_AddMutexToContextLockedList(ProcessorContext*,Mutex*);
void ARM7_RemoveMutexFromContextLockedList(ProcessorContext*,Mutex*);
void ARM7_ZeroInitializeMutex(Mutex* mutex)
{
    mutex->waitingContexts_.first = mutex->waitingContexts_.last = 0;
    mutex->ownedContext_ = 0;
    mutex->ownerRefcount_ = 0;
}

void ARM7_LockMutex(Mutex* mutex)
{
    int priorState = ARM7_DisableIRQInterrupts();
    ProcessorContext* thisContext = ARM7_ThreadSystem.activeContext;
    while (1)
    {
        if (mutex->ownedContext_ == 0)
        {
            mutex->ownedContext_ = thisContext;
            mutex->ownerRefcount_++;
            ARM7_AddMutexToContextLockedList(thisContext, mutex);
            break;
        }
        else if (mutex->ownedContext_ == thisContext)
        {
            mutex->ownerRefcount_++;
            break;
        }
        else
        {
            thisContext->blockingMutex = mutex;
            ARM7_BlockCurrentThread(&mutex->waitingContexts_);
            thisContext->blockingMutex = 0;
        }
    }
    ARM7_SetIRQInterruptState(priorState);
}

void ARM7_UnlockMutex(Mutex* mutex)
{
    int priorState = ARM7_DisableIRQInterrupts();
    ProcessorContext* thisContext = ARM7_ThreadSystem.activeContext;
    if (mutex->ownedContext_ == thisContext)
    {
        mutex->ownerRefcount_--;
        if (mutex->ownerRefcount_ == 0)
        {
            ARM7_RemoveMutexFromContextLockedList(thisContext, mutex);
            mutex->ownedContext_ = 0;
            ARM7_UnblockThreads(&mutex->waitingContexts_);
        }
    }
    ARM7_SetIRQInterruptState(priorState);
}

void ARM7_UnlockAllMutexesLockedByContext(ProcessorContext *context)
{
    while (context->lockedMutexes.pFirst != 0)
    {
            Mutex* mutex = ARM7_PopFrontMutexFromList(&context->lockedMutexes);
            mutex->ownerRefcount_ = 0;
            mutex->ownedContext_ = 0;
            ARM7_UnblockThreads(&mutex->waitingContexts_);
    }
}

void ARM7_AddMutexToContextLockedList(ProcessorContext* context, Mutex* mutex)
{
    Mutex* oldLast = context->lockedMutexes.pLast;

    if (oldLast == 0)
        context->lockedMutexes.pFirst = mutex;
    else
        oldLast->pNext_ = mutex;

    mutex->pPrev_ = oldLast;
    mutex->pNext_ = 0;
    context->lockedMutexes.pLast = mutex;
}

void ARM7_RemoveMutexFromContextLockedList(ProcessorContext* context, Mutex* mutex)
{
    Mutex* after = mutex->pNext_;
    Mutex* before = mutex->pPrev_;

    if (after == 0)
        context->lockedMutexes.pLast = before;
    else
        after->pPrev_ = before;

    if (before == 0)
        context->lockedMutexes.pFirst = after;
    else
        before->pNext_ = after;
}
