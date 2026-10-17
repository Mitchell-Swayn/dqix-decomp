#include <globaldefs.h>
#include <System/ProcessorContext.h>
#include <System/Mutex.h>

extern "C" void *ResourceQueue_PopFirstAndDecrementOwnerCountAtomically(void *);
extern "C" void func_020bf79c(void);
extern "C" void AppendAllocatorNodeToGlobalListWithIRQDisabled(void *);

// Original: arm9/main @ 0x020C015C; symbol: func_020c015c; size: 0x50.
extern "C" void BlockUntilWorkNodeAvailableAndProcessUnderMutex(char *state) {
    void *result;
block:
    BlockCurrentContext((BlockedContextList *)(state + 0x4c0));
lock:
    LockMutex((Mutex *)(state + 0x4c8));
    result=ResourceQueue_PopFirstAndDecrementOwnerCountAtomically(state + 0x4e0);
    if (result != 0) goto process;
    UnlockMutex((Mutex *)(state + 0x4c8));
    goto block;
process:
    func_020bf79c();
    AppendAllocatorNodeToGlobalListWithIRQDisabled(result);
    UnlockMutex((Mutex *)(state + 0x4c8));
    goto lock;
}
