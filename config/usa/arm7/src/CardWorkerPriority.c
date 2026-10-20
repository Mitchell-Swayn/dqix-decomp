/* Change the worker's saved and scheduler priorities under IRQ protection. */
#pragma dont_inline on
#pragma opt_propagation off
#include "BackupTransfer.h"
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern int ARM7_SetThreadPriority(ProcessorContext*,unsigned int);
// Original: arm7/wram @ 0x03802DB8; symbol: ARM7_SetCardWorkerPriority.
unsigned int ARM7_SetCardWorkerPriority(unsigned int priority) {
 register int state;
 BackupWorker *worker=&ARM7_BackupWorker;
 unsigned int previous;
 state=ARM7_DisableIRQInterrupts();
 previous=worker->priority;
 worker->priority=priority;
 ARM7_SetThreadPriority(&worker->thread,priority);
 ARM7_SetIRQInterruptState(state);
 return previous;
}
