#pragma opt_propagation off
/* Release the cartridge operation, wake waiters, then deliver its callback. */
#pragma dont_inline on
#include "BackupTransfer.h"
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_MarkThreadReady(ProcessorContext*);
extern void ARM7_WakeBlockedThreads(BlockedContextList*);
// Original: arm7/wram @ 0x038036D4; symbol: ARM7_CompleteCardOperation.
void ARM7_CompleteCardOperation(void) {
 BackupWorker *worker=&ARM7_BackupWorker;
 register int state;
 void *argument;
 void (*callback)(void*);
 worker->request->result=0;
 callback=worker->callback;
 argument=worker->userData;
 state=ARM7_DisableIRQInterrupts();
 worker->flags&=~0x4c;
 ARM7_WakeBlockedThreads(&worker->waiters);
 if(worker->flags&0x10)ARM7_MarkThreadReady(&worker->thread);
 ARM7_SetIRQInterruptState(state);
 if(callback)callback(argument);
}
