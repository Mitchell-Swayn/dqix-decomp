/* Serialize cartridge operations through the shared worker wait list. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_BlockCurrentThread(BlockedContextList*);
void ARM7_BeginCardOperation(BackupWorker *worker,void (*callback)(void*),void *userData)
{
 int state=ARM7_DisableIRQInterrupts();
 while(worker->flags&4)ARM7_BlockCurrentThread(&worker->waiters);
 worker->flags|=4;
 worker->callback=callback;
 worker->userData=userData;
 ARM7_SetIRQInterruptState(state);
}
